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
	myAbsorp.dcr = 0;
	myAbsorp.acir = 0;
	myAbsorp.dcir = 0;
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

	yn_1 = init_Absorp(yn_1);
	yn= init_Absorp(yn);
	xn_1 =init_Absorp(xn_1);
	FILE* fichier = initFichier(filename); // lecture du fichier
	while(1)
	{
		xn = lireFichier(fichier, &etat);
		if(etat==EOF)
		{
			break;
		}
		yn = iir(xn,xn_1,&yn_1);
		xn_1= xn;
	}

/*myAbsorp = lireFichier(fichier, &etat);
	while(etat != EOF)
	{
		
		NewAbsorp = iir(myAbsorp, LastAbsorp);
		LastAbsorp = NewAbsorp;
	//	myAbsorp = lireFichier(fichier, &etat);
	}
*/
	return yn;

}

/*******************************************************************************
* Function Name  : iir
* Description    : filtre passe haut
* Input          : 2 absorp 
* Return         : 1 absorp
*******************************************************************************/

absorp iir(absorp xn, absorp xn_1, absorp *yn_1)
{
	float alpha = 0.992;
	absorp yn;
	yn = init_Absorp(yn);

	//printf("xn %f %f\n", xn.acir, xn.acr);
	//printf("xn_1 %f %f\n", xn_1.acir, xn_1.acr);
	//printf("yn %f %f\n", yn.acir, yn.acr);
	//printf("yn_1 %f %f\n", yn_1->acir, yn_1->acr);
	//printf("%f", alpha *yn_1->acr);
  	yn.acir = xn.acir - xn_1.acir + (alpha * yn_1->acir);
  	yn.acr = xn.acr - xn_1.acr + (alpha * yn_1->acr);
	*yn_1 = yn;
  	return yn;
	
}