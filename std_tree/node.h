//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_NODE_H
#define PROJET_ALGO_L2_NODE_H

#include "../std_list/list.h"

typedef struct s_node{
    char value;
    struct s_node** childrens;
    int nbForms;
    t_std_list forms;
}t_node;

typedef t_node* p_node;

#endif //PROJET_ALGO_L2_NODE_H

