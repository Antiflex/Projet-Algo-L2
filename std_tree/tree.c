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

void addWord(t_tree* t, str word){ // ajoute un mot (forme de base) à l'arbre
    p_node* nodeTab = createWordNodeTab(word);
    int len = strlen(word);
    p_node current = t->root;
    for(int i=0; i<len; i++){
        return;
    }
    return;
}