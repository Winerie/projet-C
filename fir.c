/************************************************************************
* TITLE: fir.c            
* AUTHOR: Justine LE VEN et Tristan LE COZ            
* DESCRIPTION:       
* VERSION: 1.0 
************************************************************************/
#include "fir.h"

absorp firTest(char* filename)
{	
	int etat= 0;
	absorp donnees;
	absorp	myAbsorp;
	absorp	tabx[51]={0};
	FILE* fichierdata=initFichier(filename);
	
	
	myAbsorp.acr=0;
	myAbsorp.acir=0;
	while(1){
		donnees = lireFichier(fichierdata, &etat);
        if(etat==EOF){
            break;
        }
		myAbsorp = FIR (donnees, tabx);
		
	}

	finFichier(fichierdata);

	
	return myAbsorp;

}




absorp FIR (absorp donnees, absorp* tabx){
	float acr=0;
	float acir=0;
	int i=0;
	float FIR_TAPS[51]={
    1.4774946e-019,
    1.6465231e-004,
    3.8503956e-004,
    7.0848037e-004,
    1.1840522e-003,
    1.8598621e-003,
    2.7802151e-003,
    3.9828263e-003,
    5.4962252e-003,
    7.3374938e-003,
    9.5104679e-003,
    1.2004510e-002,
    1.4793934e-002,
    1.7838135e-002,
    2.1082435e-002,
    2.4459630e-002,
    2.7892178e-002,
    3.1294938e-002,
    3.4578348e-002,
    3.7651889e-002,
    4.0427695e-002,
    4.2824111e-002,
    4.4769071e-002,
    4.6203098e-002,
    4.7081811e-002,
    4.7377805e-002,
    4.7081811e-002,
    4.6203098e-002,
    4.4769071e-002,
    4.2824111e-002,
    4.0427695e-002,
    3.7651889e-002,
    3.4578348e-002,
    3.1294938e-002,
    2.7892178e-002,
    2.4459630e-002,
    2.1082435e-002,
    1.7838135e-002,
    1.4793934e-002,
    1.2004510e-002,
    9.5104679e-003,
    7.3374938e-003,
    5.4962252e-003,
    3.9828263e-003,
    2.7802151e-003,
    1.8598621e-003,
    1.1840522e-003,
    7.0848037e-004,
    3.8503956e-004,
    1.6465231e-004,
    1.4774946e-019
	};
	for (i=50;i>0;i--){
			tabx[i]=tabx[i-1];
		}
	tabx[0]=donnees;
	for (i=0;i<51;i++){
		acr=acr+FIR_TAPS[i]*tabx[i].acr;
		acir=acir+FIR_TAPS[i]*tabx[i].acir;
	}
	donnees.acr=acr;
	donnees.acir=acir;
	return donnees;
}