//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_TREE_H
#define PROJET_ALGO_L2_TREE_H

#include "node.h"
#include "str.h"

#define SIZE 10
//#define SIZE 10

typedef struct s_tree // structure d'un arbre
{
    char *nature; // précise la nature des mots stockés : nom, verbe, adjectif...
    p_node root; // racine du noeud
} t_tree, *p_tree;

//prototypes

p_node* createWordNodeTab(str word);
p_node addWord(p_node current, str word);
t_tree createEmptyTree(char class_gram[]);

int isNodeWord(p_node pn);
p_node findWordInTree(t_tree t, str word);
p_node IsWordInTree(t_tree t, str word);
bform randomBaseFormInTree(t_tree t);
str* splitStrColon(str string);
str* getAttributesTab(str information);
p_node addWordToTree(t_tree tree, str flechie, str non_flechie, str information);

#endif //PROJET_ALGO_L2_TREE_H
