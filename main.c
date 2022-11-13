//
// Created by Alexandre on 17/10/2022.
//
#include <stdio.h>
#include "tree.h"
#include <time.h>
#include "files\files.h"

int main() {
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

    t_model model2 = createRandomModel2();
    printDevModel(model2);
    */
    str mot1 = (str) calloc(4,sizeof(char));
    //mot1[0]= 'o'; mot1[1]= 'u'; mot1[2]= 'i'; mot1[3]= '\0';

    char mot2[] = "non";
    addStrChar(&mot1,'0');
    printf("%s",mot1);
    //printf("%s", concatWordAttributes(model2.words[4]));
}