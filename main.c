//
// Created by Alexandre on 17/10/2022.
//
#include <stdio.h>
#include <locale.h>
#include "tree.h"
#include <string.h>
#define TAILLE_MAX 1000/**Taille mmaximum des tableaux*/
#define SEEK_START 1/**Ligne à laquelle on commence la recherche dans le dictionnaire*/
#define SEEK_fin 50/**Ligne à laquelle on finit la recherche dans le dictionnaire*/
#include "function.h"

int main1(){
    t_tree verbes = createEmptyTree("verbes");
    p_node current = verbes.root;
    // abaisse	abaisser	Ver:IPre+SG+P1:IPre+SG+P3:SPre+SG+P1:SPre+SG+P3:ImPre+SG+P2
    addWordToTree(verbes,"avoue","avouer","Ver:IPre+SG+P1:IPre+SG+P3:SPre+SG+P1:SPre+SG+P3:ImPre+SG+P2");
    addWordToTree(verbes,"avoue","avouer","Ver:IPre+SG+P1:IPre+SG+P3:SPre+SG+P1:SPre+SG+P3:ImPre+SG+P2");
    printf("\n%s", verbes.root->children.head->nodeValue->children.head->nodeValue->children.head->nodeValue->children.head->nodeValue->children.head->nodeValue->children.head->nodeValue->forms.head->value.word);
};



int main() {

    /**Création des variables pour stocker toutes les informations des fichiers*/
    FILE* fichier = NULL;
    setlocale (LC_CTYPE,"");
    int SEEK_CURR=SEEK_START;
    char flechie[TAILLE_MAX] = "";
    char non_flechie[TAILLE_MAX] = "";
    char information[TAILLE_MAX] = "";
    char classe_gram[TAILLE_MAX] = "";
    char class_gram_verbes[]="Ver";
    char class_gram_noms[]="Nom";
    char class_gram_adjectifs[]="Adj";
    char class_gram_adverbe[]="Adv";
    //Pour implémenter les attributs dans les formes fléchies
    char *attributes[TAILLE_MAX]={"", "", "", "", "", ""};
    fichier = fopen("C:\\Users\\a\\CLionProjects\\Projet-Algo-L2\\dictionnaire_non_accentue.txt","r");
    printf("%u\n",fichier);
    if (fichier != NULL)/**Teste si le fichier est ouvert*/
    {
        p_node temp = malloc(sizeof(t_node));
        t_tree verbes = createEmptyTree(class_gram_verbes);
        t_tree noms = createEmptyTree(class_gram_noms);
        t_tree adjectifs = createEmptyTree(class_gram_adjectifs);
        t_tree adverbes = createEmptyTree(class_gram_adverbe);
        while(SEEK_CURR<=SEEK_fin) {/**On se déplace dans le fichier jusqu'à la valeur donnée*/
            fscanf(fichier, "%s   %s   %s", flechie, non_flechie,information); /**On récupère les informations du fichier*/
            Emptystr(classe_gram);
            deuxpoints(information, classe_gram, 0);
            if (!strcmp(classe_gram, class_gram_adjectifs))
                temp = addWordToTree(adjectifs, flechie, non_flechie, information);
            else if (!strcmp(classe_gram, class_gram_noms))
                temp = addWordToTree(noms, flechie, non_flechie, information);
            else if (!strcmp(classe_gram, class_gram_verbes))
                temp = addWordToTree(verbes, flechie, non_flechie, information);
            else if (!strcmp(classe_gram, class_gram_adverbe))
                temp = addWordToTree(adverbes, flechie, non_flechie, information);
            printf("%s\n", temp->forms.head->value.word);

            SEEK_CURR += 1;
            fseek(fichier, 20, SEEK_fin);
        }
        fclose(fichier);/**Ici on ferme le fichier après utilisation*/
        printf("----------\n");
        bform res;
        res = randomBaseFormInTree(noms);
        printf("%u",res.node!= NULL);
    }
    return 0;
};

