//
// Created by basti_27sky4h on 14/11/2022.
//

#include "menu.h"
int menu(){/**Menu permettant l'affichage des choix à faire */
    int a=0;
    do{
        printf("1| Formes non flechies\n2| Formes flechies\nSaisissez un nombre entre 1 et 2:");
        scanf("%d",&a);
    }while(a<1 || a>2);
    int b=0;
    if(a==1){
        do{
            printf("1| Modele numero 1 (nom  adjectif  verbe  nom)\n2| Modele numero 2 (nom  qui  verbe  verbe  nom  adjectif)\n3| Modele numero 3 (nom  verbe  verbe  adjectif  nom)\nSaisissez un nombre entre 1 et 3:");
            scanf("%d",&b);
        }while(b<1 || b>3);
        if(b==1){
            return 1;/**Formes non fléchies et modèle numéro 1 */
        }else if(b==2){
            return 2;
        }
        return 3;
        /**Formes non fléchies et modèle numéro 2 */
    }else{
        do{
            printf("1| Modele numero 1 (nom  adjectif  verbe  nom)\n2| Modele numero 2 (nom  qui  verbe  verbe  nom  adjectif)\n3| Modele numero 3 (nom  verbe  verbe  adjectif  nom)\nSaisissez un nombre entre 1 et 3:");
            scanf("%d",&b);
        }while(b<1 || b>3);
        if(b==1){
            return 4;/**Formes fléchies et modèle numéro 1 */
        }
        if(b==2){
            return 5;/**Formes fléchies et modèle numéro 2 */
        }
        return 6;
    }

}