/************************************************************************
* TITLE: affichage.c             
* AUTHOR: Justine LE VEN et Tristan LE COZ            
* DESCRIPTION:       
* VERSION: 1.0 
************************************************************************/
#include "affichage.h"


void affichage(oxy myOxy)
{
    if( access( ".verrouData", F_OK ) != -1 ){ 
        // Fichier existe
    }else{
        // Fichier n'existe pas
        FILE *verrou=fopen(".verrouData","w");
        if( verrou!=NULL){
            FILE* fichier = NULL;
            fichier = fopen("Data.txt", "w");
        
            if (fichier != NULL)
            {
                fprintf(fichier,"%d\n",myOxy.spo2);
                fprintf(fichier,"%d",myOxy.pouls);
                fclose(fichier);
            }
            fclose(verrou);
            remove(".verrouData");
        }
        

    }
		
}

