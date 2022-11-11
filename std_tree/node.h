//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_NODE_H
#define PROJET_ALGO_L2_NODE_H

#include "form_list.h"

typedef struct s_node {
    char letter;  // la lettre du noeud

    //str base; //(unused yet) forme du base si le mot représenté est la forme fléchie d'un autre mot dans l'arbre

    struct s_children_list { // la liste des enfants du noeud (liste chainée)- peut être appelée par (t_node)->children (de type t_children_list)

        struct s_child { // structure d'un enfant (un maillon de LLC) : (de type t_child)

            struct s_node *nodeValue; //pointeur vers le noeud enfant (type p_node)
            struct s_child *next; //pointeur vers le prochain enfant (type p_child)

        }* head; // pointeur vers le premier t_child

        int childNb; //nombre d'enfants du noeud
    }children;

    int nbForms; // le nombre de conjugated forms du noeud (le noeud représente un
                // mot qui est l'enchainement des lettres des noeuds précédents et de lui-même)
                // vaut 0 si le noeud ne représente pas un mot

    form_list forms; // la liste des conjugated forms du mot formé à partir du noeud
                    // (LLC de maillons contenant des str qui sont les conjugated forms)
}t_node;

/*
pour résumer la structure d'un t_node est la suivante :

s_node{
    char letter : la lettre du noeud
    t_children_list children : la liste des enfants du noeud (LLC de t_child)
    int nbForms : le nombre de conjugated forms du noeud
    form_list forms : la liste des conjugated forms (LLC de c_form)
*/

typedef struct s_children_list t_children_list;
typedef struct s_child t_child;
typedef t_child *p_child;
typedef t_node *p_node;
typedef t_node letter; //facultatif

//prototypes

p_node createNode(char letter);
p_child createChild(p_node pn);
void addConjForm(p_node pn, cform form);
p_node findChild(p_node pn, char letter);
void addChild(p_node pn, p_node childNode);
p_node findNode(p_node pn, char c);

#endif //PROJET_ALGO_L2_NODE_H

