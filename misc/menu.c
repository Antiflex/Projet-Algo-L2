//
// Created by basti_27sky4h on 14/11/2022.
//

#include "menu.h"

int menu(t_tree verbs, t_tree nouns, t_tree adjectives, t_tree adverbs){/**Menu permettant l'affichage des choix à faire */
    int a=0;
    char mot[1000]="";
    int c=0;
    do{
        printf("1| Formes non flechies\n2| Formes flechies\n3| Recherche de mot\nSaisissez un nombre entre 1 et 3:");
        scanf("%d",&a);
    }while(a<1 || a>3);
    int b=0;
    if(a==1){
        do{
            printf("1| Modele numero 1 (nom  adjectif  verbe  nom)\n2| Modele numero 2 (nom  qui  verbe  verbe  nom  adjectif)\n3| Modele numero 3 (nom  verbe  avec  nom  adjectif)\nSaisissez un nombre entre 1 et 3:");
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
                printf("1| Modele numero 1 (nom  adjectif  verbe  nom)\n2| Modele numero 2 (nom  qui  verbe  verbe  nom  adjectif)\n3| Modele numero 3 (nom  verbe  avec  nom  adjectif)\nSaisissez un nombre entre 1 et 3:");
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
            do{
                printf("1| Formes non flechies\n2| Formes flechies\nSaisissez un nombre entre 1 et 2:");
                scanf("%d", &c);
            }while(c<1 || c>2);
            switch(c) {
                case 1:
                    do {
                        printf("Saisir le mot sous sa forme non flechie a rechercher:");
                        scanf("%s", mot);
                    } while (strlen(mot) == 0);
                    searchWordInTree(nouns, mot);
                    PrintdevCform(nouns,mot);
                    searchWordInTree(verbs, mot);
                    PrintdevCform(verbs,mot);
                    searchWordInTree(adjectives, mot);
                    PrintdevCform(adjectives,mot);
                    searchWordInTree(adverbs, mot);
                    PrintdevCform(adverbs,mot);
                    Emptystr(mot);
                    break;
                case 2:
                    do {
                        printf("Saisir le mot sous sa forme flechie a rechercher:");
                        scanf("%s", mot);
                    } while (strlen(mot) == 0);
                    searchCformInTrees(nouns,verbs,adjectives,adverbs,mot);
                    break;
            }
            return 0;
        }
    }

}