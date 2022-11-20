//
// Created by basti_27sky4h on 14/11/2022.
//

#include "menu.h"

int menu(t_tree verbs, t_tree nouns, t_tree adjectives, t_tree adverbs){/**Menu permettant l'affichage des choix à faire */
    int a=0;
    char mot[1000]="";
    do{
        printf("1| Formes non flechies\n2| Formes flechies\n3| Recherche de mot\nSaisissez un nombre entre 1 et 3:");
        scanf("%d",&a);
    }while(a<1 || a>3);
    int b=0;
    if(a==1){
        do{
            printf("1| Modele numero 1\n2| Modele numero 2\n3| Modele numero 3\nSaisissez un nombre entre 1 et 3:");
            scanf("%d",&b);
        }while(b<1 || b>3);
        if(b==1){
            return 1;/**Formes non fléchies et modèle numéro 1 */
        }
        if (b==2){
            return 2;/**Formes non fléchies et modèle numéro 2 */
        }
        return 3;
    }else{
        if(a==2) {
            do {
                printf("1| Modele numero 1\n2| Modele numero 2\n3| Modele numero 3\nSaisissez un nombre entre 1 et 3:");
                scanf("%d", &b);
            } while (b < 1 || b > 3);
            if (b == 1) {
                return 4;/**Formes fléchies et modèle numéro 1 */
            }
            if (b == 2) {
                return 5;/**Formes fléchies et modèle numéro 2 */
            }
            return 6;
        }
        else{

            do {
                printf("Saisir le mot a rechercher:");
                scanf("%s", mot);
            } while (strlen(mot)==0);
            searchWordInTree(nouns,mot);
            searchWordInTree(verbs,mot);
            searchWordInTree(adjectives,mot);
            searchWordInTree(adverbs,mot);
            Emptystr(mot);
            return 0;
        }
    }

}