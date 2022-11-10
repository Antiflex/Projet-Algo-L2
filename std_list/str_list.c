//
// Created by Alexandre on 17/10/2022.
//

#include "str_list.h"

void addHeadList(str_list* list, p_str_cell pc){ //chaine un str_cell en tete de la liste (liste des formes fléchies)
        p_str_cell temp = list->head;
        list->head = pc;
        pc->next = temp;
}
