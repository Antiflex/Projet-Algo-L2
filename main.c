//
// Created by Alexandre on 17/10/2022.
//
#include <stdio.h>
#include "tree.h"
#include <time.h>
#include "files\files.h"

int main() {
    time_t t;
    srand(543848484*time(&t));
    /*
    FILE* fichier = NULL;
    setlocale (LC_CTYPE,"");
    int SEEK_CURR=SEEK_START;
    char flechie[TAILLE_MAX] = "";
    char non_flechie[TAILLE_MAX] = "";
    char information[TAILLE_MAX] = "";
    char classe_gram[TAILLE_MAX] = "";
    char information3[TAILLE_MAX] = "";
    char information4[TAILLE_MAX] = "";
    char information5[TAILLE_MAX] = "";
    char information6[TAILLE_MAX] = "";
    char information7[TAILLE_MAX] = "";
    int i;
    int j=0;
    fichier = fopen("C:\\Users\\a\\CLionProjects\\Projet-Algo-L2\\files\\dictionnaire_non_accentue.txt", "r");
    if (fichier != NULL)
    {
        while(SEEK_CURR<=SEEK_fin) {
            fscanf(fichier, "%s   %s   %s", flechie, non_flechie, information);
            i=isdeuxpoints(information);
            j=0;
            switch (i){
                case 1:
                    j= deuxpoints(information,classe_gram,j)+1;
                    deuxpoints(information,information3,j);
                    isplus(classe_gram);
                    isplus(information3);
                    printf("%s %s %s %s\n", flechie, non_flechie, classe_gram,information3);
                    SEEK_CURR+=1;
                    fseek(fichier, 20, SEEK_fin);
                    break;

                case 2:
                    j= deuxpoints(information,classe_gram,j)+1;
                    j=deuxpoints(information,information3,j)+1;
                    deuxpoints(information,information4,j);
                    isplus(classe_gram);
                    isplus(information3);
                    isplus(information4);
                    printf("%s %s %s %s %s  \n", flechie, non_flechie, classe_gram,information3,information4);
                    SEEK_CURR+=1;
                    fseek(fichier, 20, SEEK_fin);
                    break;

                case 3:
                    j= deuxpoints(information,classe_gram,j)+1;
                    j=deuxpoints(information,information3,j)+1;
                    j=deuxpoints(information,information4,j)+1;
                    deuxpoints(information,information5,j);
                    isplus(classe_gram);
                    isplus(information3);
                    isplus(information4);
                    isplus(information5);
                    printf("%s %s %s %s %s %s  \n", flechie, non_flechie, classe_gram,information3,information4,information5);
                    SEEK_CURR+=1;
                    fseek(fichier, 20, SEEK_fin);
                    break;

                case 4:
                    j= deuxpoints(information,classe_gram,j)+1;
                    j=deuxpoints(information,information3,j)+1;
                    j=deuxpoints(information,information4,j)+1;
                    j=deuxpoints(information,information5,j)+1;
                    deuxpoints(information,information6,j);
                    isplus(classe_gram);
                    isplus(information3);
                    isplus(information4);
                    isplus(information5);
                    isplus(information6);
                    printf("%s %s %s %s %s %s %s \n", flechie, non_flechie, classe_gram,information3,information4,information5,information6);
                    SEEK_CURR+=1;
                    fseek(fichier, 20, SEEK_fin);
                    break;

                case 5:
                    j= deuxpoints(information,classe_gram,j)+1;
                    j=deuxpoints(information,information3,j)+1;
                    j=deuxpoints(information,information4,j)+1;
                    j=deuxpoints(information,information5,j)+1;
                    j=deuxpoints(information,information6,j)+1;
                    deuxpoints(information,information7,j);
                    isplus(classe_gram);
                    isplus(information3);
                    isplus(information4);
                    isplus(information5);
                    isplus(information6);
                    isplus(information7);
                    printf("%s %s %s %s %s %s %s %s\n", flechie, non_flechie, classe_gram,information3,information4,information5,information6,information7);
                    SEEK_CURR+=1;
                    fseek(fichier, 20, SEEK_fin);
                    break;
            }
        }
        fclose(fichier);
    }
    return 0;
    */
    t_model model2 = createRandomModel2();
    printDevModel(model2);
    model2.words[2].attributes[0] = "IPre";
    model2.words[2].attributes[1] = "SG";
    model2.words[2].attributes[2] = "P3";
    /*
    str mot1 = (str) calloc(4,sizeof(char));
    //mot1[0]= 'o'; mot1[1]= 'u'; mot1[2]= 'i'; mot1[3]= '\0';

    char mot2[] = "non";
    addStrChar(&mot1,'0');
    printf("%s",mot1);
     */
    //abaisse	abaisser	Ver:IPre+SG+P1:IPre+SG+P3:SPre+SG+P1:SPre+SG+P3:ImPre+SG+P2
    cform forme1;
    forme1.nbAttributes = 5;
    forme1.word = calloc(8,sizeof(char));
    forme1.word = "abaisse";
    forme1.attributes = calloc(5,sizeof(str));
    str tab[5] = {"IPre SG P1", "IPre SG P3", "SPre SG P1", "SPre SG P3", "ImPre SG P2"};
    forme1.attributes = tab;

    printf("a trouver :[%s]\n", concatWordAttributes(model2.words[2]));
    printf("%d",compareWordWithCform(model2.words[2],forme1));
}