/************************************************************************
* TITLE: iir.h             
* AUTHOR: Justine LE VEN et Tristan LE COZ            
* DESCRIPTION:       
* VERSION: 1.0 
************************************************************************/
#include "define.h"
#include "fichiers.h"


absorp iirTest(char* filename);
absorp init_Absorp(absorp myabsorp);
absorp iir(absorp xn, absorp xn_1, absorp *yn_1);