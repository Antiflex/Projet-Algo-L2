//
// Created by Alexandre on 17/10/2022.
//

#include "tree.h"
#include <stdlib.h>
#include "function.h"
#define MAX 10

p_node* createWordNodeTab(str word){ //crée un tableau de p_node qui, dans l'ordre, forment un mot,
                                    // les noeuds créés n'ont aucun lien de parenté
    int len = strlen(word);
    p_node* nodeTab = (p_node*) calloc(len,sizeof(p_node));
    for(int i=0; i<len; i++)
        nodeTab[i] = createNode(word[i]);

    return nodeTab;
}

p_node addWord(p_node current, str word){ // ajoute un mot (forme de base) à l'arbre à partir d'un noeud
   p_node temp = current;
   int i=1;
   while (i<strlen(word)){
       p_node IsChild = findChild(temp, word[i]); //on cherche si la 2ème lettre existe dans les enfants du noeud current
       if ( IsChild != NULL){
            //si la lettre existe :
            temp = IsChild;
       }
       else{ // problème ici
           printf("k\n");
           p_node new_child= createNode(word[i]);
           addChild(temp, new_child);
           temp = new_child;
       }
       i++;
   }
   return temp; //retourne la fin du mot /dernière lettre
}

str* splitStrColon(str string){ // renvoie une liste de str à partir d'une str qui utilise ':' comme séparateur
    int nbStr = isdeuxpoints(string)+1;
    str* tabStr = (str*) calloc(nbStr, sizeof(str));
    int strIndex = 0;
    for(int i =0; i<nbStr; i++){
        tabStr[i] = (str) calloc(MAX,sizeof(char));
        strIndex = deuxpoints(string,tabStr[i],strIndex)+1;
        tabStr[i] = realloc(tabStr[i],(strlen(tabStr[i])+1)*sizeof(char));
    }
    return tabStr;
}

p_node addWordToTree(t_tree tree, str non_flechie, str classe_gram, str information){
    int nbAttributs = isdeuxpoints(information);
    str* tabInfo = (str*) calloc(nbAttributs,sizeof(str));
    int strInfoIndex = 0;
    strInfoIndex = deuxpoints(information, NULL, strInfoIndex) + 1;
    for(int i = 0; i< nbAttributs; i++){
        strInfoIndex = deuxpoints(information, classe_gram, strInfoIndex) + 1;

    }
}

t_tree createEmptyTree(char class_gram[]){ // crée un arbre avec un noeud root qui a pour valeur ' '
    t_tree T;
    T.root = createNode('0');
    T.nature= class_gram;
    return T;
}

/* t_tree createTree(char *TypeOfWord){ // ajouter d'autre argument pour utiliser les fonctions de Bastien
    t_tree T;
    T.nature = TypeOfWord;
    //forme de base, fléchie, genre, nombre... de la ligne 1 du dico à récupérer avec les fonctions de bastien
    char BaseForm1[]= ;
    char FlexForm1[]= ;
    char *Parameters1[]= ;

    //forme de base, fléchie, genre, nombre... de la ligne 2 du dico
    char BaseForm2[]= ;
    char FlexForm2[]= ;
    char *Parameters2[]= ;

    //On ajoute le premier mot du dico
    T.root= createNode(BaseForm1[0]);
    p_node StartLetter = T.root; //la lettre du début de notre mot
    p_node EndLetter = addWord(StartLetter, BaseForm1); //la lettre de la fin de notre mot
    addConjForm(EndLetter, createCform(FlexForm1, Parameters1)); // on ajoute la forme fléchie

    //Boucle pour ajouter le reste de notre dico à m'arbre
    while ( ){ //temps qu'on  a pas parcouru tout le dico
        if (BaseForm1 == BaseForm2){
            addConjForm(EndLetter, createCform(FlexForm2, Parameters2));
        }
        else{
            //trouver un noeud où ajouter la nouvelle forme de base
            //vérifier pour les enfants du premier noeud
        }

    }
}*/