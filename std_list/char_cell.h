//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_CHAR_CELL_H
#define PROJET_ALGO_L2_CHAR_CELL_H

struct s_char_cell
{
    char value;
    struct s_char_cell *next;
};

typedef struct s_char_cell t_char_cell, *p_char_cell;

p_char_cell createCharCell(char);

#endif //PROJET_ALGO_L2_CHAR_CELL_H
