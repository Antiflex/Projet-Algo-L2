//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_FORM_CELL_H
#define PROJET_ALGO_L2_FORM_CELL_H


#include "conjugated_form.h"

struct s_form_cell
{
    cform value;
    struct s_form_cell* next;
};

typedef struct s_form_cell t_form_cell, *p_form_cell;

//prototypes

p_form_cell createCell(cform form);

#endif //PROJET_ALGO_L2_FORM_CELL_H
