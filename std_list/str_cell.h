//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_STR_CELL_H
#define PROJET_ALGO_L2_STR_CELL_H


#include <string.h>

typedef char* str;

struct s_str_cell
{
    str value;
    struct s_str_cell *next;
};

typedef struct s_str_cell t_str_cell, *p_str_cell;

#endif //PROJET_ALGO_L2_STR_CELL_H
