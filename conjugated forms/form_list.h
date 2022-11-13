//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_FORM_LIST_H
#define PROJET_ALGO_L2_FORM_LIST_H

#include "form_cell.h"

typedef struct{
    p_form_cell head;  // liste qui stock les conjugated forms d'un noeud (stock des maillons contenant des structures cform)
}form_list;

//prototypes

void addHeadList(form_list* list, p_form_cell pc);


#endif //PROJET_ALGO_L2_FORM_LIST_H
