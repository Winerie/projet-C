/************************************************************************
* TITLE: affichage.c             
* AUTHOR: Justine LE VEN et Tristan LE COZ            
* DESCRIPTION:       
* VERSION: 1.0 
************************************************************************/

#include "affichage.h"
#include "iir.h"

int main (){
    oxy test;
   
    absorp myAbsorp;
    test.pouls=100;
    test.spo2=105;
    affichage(test);
    myAbsorp = iirTest("record1_fir.dat");
    printf("%f %f", myAbsorp.acr, myAbsorp.acir);
}