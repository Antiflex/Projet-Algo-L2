//
// Created by Alexandre on 17/10/2022.
//

#include "form_cell.h"

p_form_cell createCell(cform* form){
    p_form_cell pc = (p_form_cell) malloc(sizeof(t_form_cell));
    pc->value = form;
    pc->next = NULL;
    return pc;
}
