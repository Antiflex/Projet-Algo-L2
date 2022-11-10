//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_STR_LIST_H
#define PROJET_ALGO_L2_STR_LIST_H

#include "str_cell.h"

typedef struct{
    p_str_cell head;  // liste qui stock les formes fléchies d'un noeud (stock des maillons contenant des str)
}str_list;

//prototypes

void addHeadList(str_list* list, p_str_cell pc);

#endif //PROJET_ALGO_L2_STR_LIST_H
