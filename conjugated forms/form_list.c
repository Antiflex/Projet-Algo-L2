//
// Created by Alexandre on 17/10/2022.
//

#include "form_list.h"

void addHeadList(form_list* list, p_form_cell pc){ //chaine un str_cell en tete de la liste (liste des conjugated forms)
        p_form_cell temp = list->head;
        list->head = pc;
        pc->next = temp;
}
