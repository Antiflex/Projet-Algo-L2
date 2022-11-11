//
// Created by Alexandre on 17/10/2022.
//

#include "tree.h"
#include <stdlib.h>

p_node* createWordNodeTab(str word){ //crée un tableau de p_node qui, dans l'ordre, forment un mot,
                                    // les noeuds créés n'ont aucun lien de parenté
    int len = strlen(word);
    p_node* nodeTab = (p_node*) calloc(len,sizeof(p_node));
    for(int i=0; i<len; i++)
        nodeTab[i] = createNode(word[i]);

    return nodeTab;
}

void addWord(p_node current, str word){ // ajoute un mot (forme de base) à l'arbre à partir d'un noeud
   p_node temp = current;
    for(int i=1; i<strlen(word); i++){

        p_node IsChild = findChild(temp, word[i]); //on cherche si la 2ème lettre existe dans les enfants du noeud current
        if ( IsChild != NULL){
            //si la lettre existe :
            temp = IsChild;
        }
        else{
            p_node new_child= createNode(word[i]);
            temp = new_child;
            addChild(temp, new_child);
        }
    }
}