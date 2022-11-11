//
// Created by Alexandre on 17/10/2022.
//

#include "node.h"
#include <stdlib.h>

p_node createNode(char letter){ // crée un noeud de l'arbre dont la lettre est en paramètre
    p_node pn = (p_node) malloc(sizeof (t_node));
    pn->letter = letter;
    pn->nbForms = 0;
    return pn;
}

p_child createChild(p_node pn){ // crée un maillon enfant : un maillon qui a pour valeur un p_node
    p_child pc = (p_child) malloc(sizeof(t_child));
    pc->nodeValue = pn;
    pc->next = NULL
    return pc;
}

void addConjForm(p_node pn, cform form){ // ajoute un mot (forme de type cform) à la liste des conjugated forms d'un noeud
    pn->nbForms++;
    p_form_cell pc = createCell(form);
    addHeadList(&pn->forms,pc);
}

p_node findChild(p_node pn, char letter){ // cherche un p_node dans la liste des enfants de pn dont la lettre est "letter"
                                            // retourne le p_node si trouvé, NULL sinon
    p_child current = pn->children.head;
    while(current != NULL && current->nodeValue->letter != letter){
        current = current->next;
    }
    if (current == NULL)
        return  NULL;
    return current->nodeValue;
}

void addChild(p_node pn, p_node childNode){ // ajoute un enfant dans la liste des enfants de pn
    t_children_list cList = pn->children;
    p_child newChild = createChild(childNode);
    if(cList.head != NULL){ //la liste n'est pas vide / le noeud possède des enfants
        p_child temp = cList.head;
        cList.head = newChild;
        newChild->next = temp;
    }
    else{ //la liste est vide / le noeud ne possède pas d'enfant
        cList.head = newChild;
    }
    cList.childNb++;
}