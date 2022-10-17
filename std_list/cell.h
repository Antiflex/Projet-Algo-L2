//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_CELL_H
#define PROJET_ALGO_L2_CELL_H

struct s_cell
{
    char value;
    struct s_cell *next;
};

typedef struct s_cell t_cell, *p_cell;

#endif //PROJET_ALGO_L2_CELL_H
