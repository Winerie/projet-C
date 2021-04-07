#include "affichage.h"
#include "fir.h"
int main (){
   absorp test= firTest("record1.dat");
   printf("\n %f \n %f",test.acr, test.acir);
}