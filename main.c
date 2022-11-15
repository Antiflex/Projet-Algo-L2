//
// Created by Alexandre on 17/10/2022.
//
#include <stdio.h>
#include <locale.h>
#include "tree.h"
#include <time.h>

#define TAILLE_MAX 1000/**Taille mmaximum des tableaux*/
#define SEEK_START 1/**Ligne à laquelle on commence la recherche dans le dictionnaire*/
#define SEEK_fin 500/**Ligne à laquelle on finit la recherche dans le dictionnaire*/
#include "function.h"

int main1(){
    t_tree verbes = createEmptyTree("verbes");
    p_node current = verbes.root;
    // abaisse	abaisser	Ver:IPre+SG+P1:IPre+SG+P3:SPre+SG+P1:SPre+SG+P3:ImPre+SG+P2
    addWordToTree(verbes,"avoue","avouer","Ver:IPre+SG+P1:IPre+SG+P3:SPre+SG+P1:SPre+SG+P3:ImPre+SG+P2");
    addWordToTree(verbes,"avoue","avouer","Ver:IPre+SG+P1:IPre+SG+P3:SPre+SG+P1:SPre+SG+P3:ImPre+SG+P2");
    printf("\n%s", verbes.root->children.head->nodeValue->children.head->nodeValue->children.head->nodeValue->children.head->nodeValue->children.head->nodeValue->children.head->nodeValue->forms.head->value->word);
};



int main() {
    /**initalisation de la see pour l'aléatoire*/
    time_t t;
    srand(time(&t));
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
    fichier = fopen("\C:\\Users\\Alexandre\\Downloads\\dictionnaire_non_accentue\\dictionnaire_non_accentue.txt","r");
    printf("%u\n",fichier);
    if (fichier != NULL)/**Teste si le fichier est ouvert*/
    {
        p_node temp ;
        t_tree verbes = createEmptyTree(class_gram_verbes);
        t_tree noms = createEmptyTree(class_gram_noms);
        t_tree adjectifs = createEmptyTree(class_gram_adjectifs);
        t_tree adverbes = createEmptyTree(class_gram_adverbe);
        while(SEEK_CURR<=SEEK_fin) {/**On se déplace dans le fichier jusqu'à la valeur donnée*/
            fscanf(fichier, "%s   %s   %s", flechie, non_flechie,information); /**On récupère les informations du fichier*/
            Emptystr(classe_gram);
            deuxpoints(information, classe_gram, 0);
            printf("%s : ",classe_gram);
            if (!strcmp(classe_gram, class_gram_adjectifs))
                temp = addWordToTree(adjectifs, flechie, non_flechie, information);
            else if (!strcmp(classe_gram, class_gram_noms))
                temp = addWordToTree(noms, flechie, non_flechie, information);
            else if (!strcmp(classe_gram, class_gram_verbes))
                temp = addWordToTree(verbes, flechie, non_flechie, information);
            else if (!strcmp(classe_gram, class_gram_adverbe))
                temp = addWordToTree(adverbes, flechie, non_flechie, information);
            printf("%d :", temp->nbForms);
            printf("%c :%s\n", temp->letter,temp->forms.head->value->word);

            SEEK_CURR += 1;
            fseek(fichier, 20, SEEK_fin);
        }
        fclose(fichier);/**Ici on ferme le fichier après utilisation*/
        printf("-----tests-----\n");

        p_node aba = isWordInTree(verbes,"abaisser");
        cform* forme1 = aba->forms.head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->value;
        printDevCform(*forme1);

        printf("%d\n",noms.root->children.head->nodeValue->nbForms);
        printf("%s\n",noms.root->children.head->nodeValue->forms.head->value->word);
        bform* res;
        t_model model1 = createRandomModel2();
        printDevModel(model1);
        res = generateBasePhraseTab(verbes,noms,adjectifs,adverbes,model1);
        bform rForm = randomBaseFormInTree(noms);
        printf("bform : %s\n",rForm.word);
        printDevCform(*rForm.node->forms.head->value);
        printf("form printed\n");
        str phrase = generateBasePhraseStr(verbes,noms,adjectifs,adverbes,model1);
        printf("%s",phrase);

    }
    return 0;
};

