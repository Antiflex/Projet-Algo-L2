//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_TREE_H
#define PROJET_ALGO_L2_TREE_H

#include "node.h"
//#define SIZE 10

typedef struct s_tree
{
    char *nature; // précise la nature des mots stockés : nom, verbe, adjectif...
    p_node root; // racine du noeud
} t_tree, *p_tree;

//prototypes

p_node* createWordNodeTab(str word);
p_node addWord(p_node current, str word);
t_tree createEmptyTree(char class_gram[]);
str* splitStrColon(str string);
str* getAttributesTab(str information);
p_node addWordToTree(t_tree tree, str flechie, str non_flechie, str information);
int isNodeWord(p_node pn);
p_node findWordInTree(t_tree tree, str word);
p_node isWordInTree(t_tree tree, str word);
bform randomBaseFormInTree(t_tree t);

#endif //PROJET_ALGO_L2_TREE_H
