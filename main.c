//
// Created by Alexandre on 17/10/2022.
//
#include <stdio.h>
#include <locale.h>
#include <locale.h>
#include "tree.h"
#define TAILLE_MAX 1000/**Taille mmaximum des tableaux*/
#define SEEK_START 1/**Ligne à laquelle on commence la recherche dans le dictionnaire*/
#define SEEK_fin 50/**Ligne à laquelle on finit la recherche dans le dictionnaire*/
#include "function.h"
int main() {
    /**Création des variables pour stocker toutes les informations des fichiers*/
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
    fichier = fopen("dictionnaire_non_accentue.txt", "r");/**Ouverture du fichier */

    if (fichier != NULL)/**Teste si le fichier est ouvert*/
    {
        while(SEEK_CURR<=SEEK_fin) {/**On se déplace dans le fichier jusqu'à la valeur donnée*/
            fscanf(fichier, "%s   %s   %s", flechie, non_flechie, information); /**On récupère les informations du fichier*/
            i=isdeuxpoints(information); /**On compte le nombre de deux points dans information*/
            j=0;
            switch (i){/**En fonction du nombre de deux points on change de cas*/
                case 0:/**Ici il n'y a pas de deux points on enlève donc juste les plus pour pouvoir l'implémenter dans l'abre puis on vide les str*/
                    isplus(information);
                    printf("%s %s %s",flechie,non_flechie,information);
                    Emptystr(information);
                    break;
                case 1:/**Ici il y a un seul deux points on l'enlève et on enlève donc les plus de chaque informations seondaires pour pouvoir l'implémenter dans l'abre puis on vide les str*/
                    j= deuxpoints(information,classe_gram,j)+1;
                    deuxpoints(information,information3,j);
                    isplus(classe_gram);
                    isplus(information3);
                    printf("%s %s %s %s\n", flechie, non_flechie, classe_gram,information3);
                    SEEK_CURR+=1;
                    fseek(fichier, 20, SEEK_fin);
                    Emptystr(information);
                    Emptystr(information3);
                    Emptystr(classe_gram);
                    break;

                case 2:/**Ici il y a deux deux points on les enlève et on enlève donc les plus de chaque informations seondaires pour pouvoir l'implémenter dans l'abre puis on vide les str*/
                    j= deuxpoints(information,classe_gram,j)+1;
                    j=deuxpoints(information,information3,j)+1;
                    deuxpoints(information,information4,j);
                    isplus(classe_gram);
                    isplus(information3);
                    isplus(information4);
                    printf("%s %s %s %s %s  \n", flechie, non_flechie, classe_gram,information3,information4);
                    SEEK_CURR+=1;
                    fseek(fichier, 20, SEEK_fin);
                    Emptystr(information);
                    Emptystr(information3);
                    Emptystr(classe_gram);
                    Emptystr(information4);
                    break;

                case 3:/**Ici il y a trois deux points on les enlève et on enlève donc les plus de chaque informations seondaires pour pouvoir l'implémenter dans l'abre puis on vide les str*/
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
                    Emptystr(information);
                    Emptystr(information3);
                    Emptystr(classe_gram);
                    Emptystr(information4);
                    Emptystr(information5);
                    break;

                case 4:/**Ici il y a quatre deux points on les enlève et on enlève donc les plus de chaque informations seondaires pour pouvoir l'implémenter dans l'abre puis on vide les str*/
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
                    Emptystr(information);
                    Emptystr(information3);
                    Emptystr(classe_gram);
                    Emptystr(information4);
                    Emptystr(information5);
                    Emptystr(information6);
                    break;

                case 5:/**Ici il y a cinq deux points on les enlève et on enlève donc les plus de chaque informations seondaires pour pouvoir l'implémenter dans l'abre puis on vide les str*/
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
                    Emptystr(information);
                    Emptystr(information3);
                    Emptystr(classe_gram);
                    Emptystr(information4);
                    Emptystr(information5);
                    Emptystr(information6);
                    Emptystr(information7);
                    break;

            }
        }
        fclose(fichier);/**Ici on ferme le fichier après utilisation*/
    }
>>>>>>>>> Temporary merge branch 2
    return 0;
}

