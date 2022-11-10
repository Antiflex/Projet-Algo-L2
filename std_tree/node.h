//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_NODE_H
#define PROJET_ALGO_L2_NODE_H

#include "../std_list/str_list.h"

typedef struct s_node {
    char value;  // la lettre du noeud

    struct s_children_list { // la liste des enfants du noeud (liste chainée)- peut être appelée par (s_node)->children (de type children_list)

        struct s_child { // structure d'un enfant (un maillon de LLC) : (de type child)

            struct s_node *nodeValue; //pointeur vers le noeud enfant (type p_node)
            struct s_child *next; //pointeur vers le prochain enfant (type p_child)
        } head;

        int childNb; //nombre d'enfants du noeud
    }children;

    int nbForms; // le nombre de formes fléchies du noeud (le noeud représente un
                // mot qui est l'enchainement des lettres des noeuds précédents et de lui-même)
                // vaut 0 si le noeud ne représente pas un mot

    str_list forms; // pointeur vers la liste des formes fléchies du mot formé à partir du noeud
                    // (LLC de maillons contenant des str qui sont les formes fléchies)
}t_node;

typedef struct s_children_list children_list;
typedef struct s_child child;
typedef child *p_child;
typedef t_node *p_node;
typedef t_node letter; //facultatif

//prototypes

p_node createNode(char letter);

#endif //PROJET_ALGO_L2_NODE_H

