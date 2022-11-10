//
// Created by Alexandre on 17/10/2022.
//

#include "node.h"

p_node createNode(char letter){ // crée un noeud de l'arbre dont la lettre est en paramètre
    p_node pn;
    pn->value = letter;
    pn->nbForms = 0;
    pn->children = NULL;
    pn->forms = NULL;
    return pn;
}

void addFlexedForm(p_node pn, str word){
    pn->nbForms++;
    p_str_cell pc = createCell(word);
    addHeadList(&pn->forms,pc);
}