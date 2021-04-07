/************************************************************************
* TITLE: iir.c            
* AUTHOR: Justine LE VEN et Tristan LE COZ            
* DESCRIPTION:       
* VERSION: 1.0 
************************************************************************/
#include "iir.h"

/*******************************************************************************
* Function Name  : init_Absorp
* Description    : mise a 0 d'une variable absorp  
* Input          : absorp
* Return         : absorp
*******************************************************************************/
absorp init_Absorp(absorp myAbsorp)
{
	myAbsorp.acr = 0;
//	myAbsorp.dcr = 0;
	myAbsorp.acir = 0;
//	myAbsorp.dcir = 0;
	return myAbsorp;
}

/*******************************************************************************
* Function Name  : iirTest
* Description    : permet de tester la fonction irr
* Input          : char *, un fichier 
* Return         : int
*******************************************************************************/
absorp iirTest(char* filename)
{
	absorp xn;
	absorp xn_1;
	absorp yn_1;
	absorp yn;
	int etat;

	yn_1 = init_Absorp(yn_1); // initialisation a 0
	yn= init_Absorp(yn); //initialisation a 0
	xn_1 =init_Absorp(xn_1); // initialisation a 0
	FILE* fichier = initFichier(filename); // lecture du fichier
/*	while(1)
	{
		xn = lireFichier(fichier, &etat); // lecture ligne par ligne, attribution a xn
		if(etat==EOF)
		{
			break; // changer ça, sa fait perdre des points en qualimétrie
		}
		yn = iir(xn,xn_1,&yn_1);
		xn_1= xn;
	} 
	*/

	xn = lireFichier(fichier, &etat);
	while(etat != EOF)
	{
		yn = iir(xn,xn_1,&yn_1);
		xn_1= xn;
		xn = lireFichier(fichier, &etat);
	}

	return yn;

}

/*******************************************************************************
* Function Name  : iir
* Description    : filtre passe haut
* Input          : 2 absorp: xn & xn_1
* entré/sortie	 : yn_1
* Return         : 1 absorp: yn
*******************************************************************************/

absorp iir(absorp xn, absorp xn_1, absorp *yn_1)
{
	float alpha = 0.992; // arrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
	absorp yn;
	yn = init_Absorp(yn); // on initialise yn a 0
	yn.dcr=xn.dcr;
	yn.dcir=xn.dcir;
  	yn.acir = xn.acir - xn_1.acir + (alpha * yn_1->acir); // formule donnée 
  	yn.acr = xn.acr - xn_1.acr + (alpha * yn_1->acr); // formule donnée
	*yn_1 = yn; // on attribu l'ancienne valeur de yn a yn_1
	printf("%f %f %f %f\n", yn.acir,yn.acr,yn.dcir,yn.dcr);
  	return yn;
	
}