//
// Created by Alexandre on 17/10/2022.
//
#include <stdio.h>
#include "tree.h"

#include <locale.h>
#define TAILLE_MAX 1000
#define SEEK_START 1
#define SEEK_fin 50
#include "function.h"

int main() {
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
    fichier = fopen("dictionnaire_non_accentue.txt", "r");

    // on crée les différents types d'arbres vides
    t_tree verbes= createEmptyTree("Verbes");
    t_tree adjectifs= createEmptyTree("Adjectifs");
    t_tree noms= createEmptyTree("Noms");
    t_tree adverbes= createEmptyTree("Adverbes");

    //Pour comparer et ensuite implémenter dans le bon arbre
    char class_gram_verbes[]="Ver";
    char class_gram_noms[]="Nom";
    char class_gram_adjectifs[]="Adj";
    char class_gram_adverbe[]="Adv";

    p_node temp;
    //Pour implémenter les attributs dans les formes fléchies
    char *attributes[TAILLE_MAX]={"", "", "", "", "", ""};
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
                    // création du tableau d'attributs qui sera ajouté à la forme fléchie de type cform
                    attributes[0]=information3;

                    //Choix de l'arbre où implémenter le mot
                    if (classe_gram == class_gram_verbes){
                        printf("verbe\n");
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                           temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adjectifs){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_noms){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adverbe){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }

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

                    // création du tableau d'attributs qui sera ajouté à la forme fléchie de type cform
                    attributes[0]=information3;
                    attributes[1]=information4;

                    //Choix de l'arbre où implémenter le mot
                    //Choix de l'arbre où implémenter le mot
                    if (classe_gram == class_gram_verbes){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adjectifs){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_noms){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adverbe){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }

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
                    attributes[0]=information3;
                    attributes[1]=information4;
                    attributes[2]=information5;

                    //Choix de l'arbre où implémenter le mot
                    if (classe_gram == class_gram_verbes){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adjectifs){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_noms){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adverbe){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }

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
                    // création du tableau d'attributs qui sera ajouté à la forme fléchie de type cform
                    attributes[0]=information3;
                    attributes[1]=information4;
                    attributes[2]=information5;
                    attributes[3]=information6;

                    //Choix de l'arbre où implémenter le mot
                    if (classe_gram == class_gram_verbes){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adjectifs){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_noms){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adverbe){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }

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
                    // création du tableau d'attributs qui sera ajouté à la forme fléchie de type cform
                    attributes[0]=information3;
                    attributes[1]=information4;
                    attributes[2]=information5;
                    attributes[3]=information6;
                    attributes[4]=information7;

                    //Choix de l'arbre où implémenter le mot
                    if (classe_gram == class_gram_verbes){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adjectifs){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_noms){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }else if (classe_gram == class_gram_adverbe){
                        if (findChild(verbes.root, non_flechie[0]) == NULL){
                            temp=addWord(createNode(non_flechie[0]),non_flechie);
                        }
                        else{
                            temp= addWord(verbes.root, non_flechie);
                        }
                        addConjForm(temp, createCform(attributes, non_flechie, i));
                    }

                    SEEK_CURR+=1;
                    fseek(fichier, 20, SEEK_fin);
                    break;

            }
        }
        fclose(fichier);

        /*
        p_child tmp=noms.root->children.head;
        while (tmp != NULL){
            printf("%c ", tmp->nodeValue->letter);
            tmp=tmp->next;
        }
        */

    }
    return 0;
}


