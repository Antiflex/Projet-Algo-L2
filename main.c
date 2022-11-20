//
// Created by Alexandre on 17/10/2022.
//
#include <stdio.h>
#include <locale.h>
#include "tree.h"
#include <time.h>
#include "function.h"
#include "menu.h"

#define TAILLE_MAX 1000/**Taille mmaximum des tableaux*/
#define SEEK_START 1/**Ligne à laquelle on commence la recherche dans le dictionnaire*/
#define SEEK_fin 287976/**Ligne à laquelle on finit la recherche dans le dictionnaire*/

int main() {
    /**initalisation de la see pour l'aléatoire*/
    time_t t;
    srand(time(&t));
    /**Création des variables pour stocker toutes les informations des fichiers*/
    FILE *fichier = NULL;
    setlocale(LC_CTYPE, "");
    int SEEK_CURR = SEEK_START;
    char flechie[TAILLE_MAX] = "";
    char non_flechie[TAILLE_MAX] = "";
    char information[TAILLE_MAX] = "";
    char classe_gram[TAILLE_MAX] = "";
    int i;
    int j = 0;
    fichier = fopen("dictionnaire_non_accentue.txt", "r");/**Ouverture du fichier */
    // on crée les différents types d'arbres vides
    t_tree verbes= createEmptyTree("Verbes");
    t_tree adjectifs= createEmptyTree("Adjectifs");
    t_tree noms= createEmptyTree("Noms");
    t_tree adverbes= createEmptyTree("Adverbes");

    //Pour comparer et ensuite implémenter dans le bon arbre
    char class_gram_verbes[TAILLE_MAX]="Ver";
    char class_gram_noms[]="Nom";
    char class_gram_adjectifs[]="Adj";
    char class_gram_adverbe[]="Adv";

    p_node temp;
    //Pour implémenter les attributs dans les formes fléchies
    char *attributes[TAILLE_MAX]={"", "", "", "", "", ""};

    if (fichier != NULL)/**Teste si le fichier est ouvert*/
    {
        while (SEEK_CURR <= SEEK_fin) {/**On se déplace dans le fichier jusqu'à la valeur donnée*/
            fscanf(fichier, "%s   %s   %s", flechie, non_flechie,information); /**On récupère les informations du fichier*/
            /**On compte le nombre de deux points dans information*/
            j = 0;
            deuxpoints(information, classe_gram, j);
            i = choixclasse_gram(classe_gram);
            Emptystr(classe_gram);
            if (i != 0) {
                switch (i) {/**En fonction de l'attribut information on change de cas*/
                    case 1://Cas étant verbe
                        addWordToTree(verbes, flechie, non_flechie, information);
                        break;
                    case 2://Cas étant adjectif
                        addWordToTree(adjectifs, flechie, non_flechie, information);
                        break;
                    case 3://Cas étant adverbe
                        addWordToTree(adverbes, flechie, non_flechie, information);
                        break;
                    case 4://Cas étant noms
                        addWordToTree(noms, flechie, non_flechie, information);
                        break;
                }
            }
            i=1;
            SEEK_CURR++;
        }
        fclose(fichier);/**Ici on ferme le fichier après utilisation*/
    }
    int b=1;
    do {
        int a = menu(verbes,noms,adjectifs,adverbes);
        t_model model;
        switch (a){
            case 0:
                break;
            case 1:
                model = createRandomModel1();
                printDevModel(model);
                printf("\n%s\n",generateBasePhraseStr(verbes,noms,adjectifs,adjectifs,model));
                break;
            case 2:
                model = createRandomModel2();
                printDevModel(model);
                printf("\n%s\n",generateBasePhraseStr(verbes,noms,adjectifs,adjectifs,model));
                break;
            case 3:
                model = createRandomModel3();
                printDevModel(model);
                printf("\n%s\n",generateBasePhraseStr(verbes,noms,adjectifs,adjectifs,model));
                break;
            case 4:
                model = createRandomModel1();
                printDevModel(model);
                PrintCform(model,noms,verbes,adjectifs,adverbes);
                break;
            case 5:
                model = createRandomModel2();
                printDevModel(model);
                PrintCform(model,noms,verbes,adjectifs,adverbes);
                break;
            case 6:
                model = createRandomModel3();
                printDevModel(model);
                PrintCform(model,noms,verbes,adjectifs,adverbes);
                break;
        }
        printf("\n");
        do{
            printf("Continuer tapez 1 sinon 0:");
            scanf("%d",&b);
            scanf("%*c");
            printf("\n");
        }while(b<0 || b>1);

    }while (b==1);
    return 0;
};

