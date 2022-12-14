//
// Created by Alexandre on 17/10/2022.
//

#ifndef PROJET_ALGO_L2_TREE_H
#define PROJET_ALGO_L2_TREE_H

#include "node.h"
#include "str.h"

#define SIZE 10
#include "model.h"
//#define SIZE 10

typedef struct s_tree // structure d'un arbre
{
    char *nature; // précise la nature des mots stockés : nom, verbe, adjectif...
    p_node root; // racine du noeud
} t_tree, *p_tree;

//prototypes

t_tree createEmptyTree(char class_gram[]);
str* splitStrColon(str string);
str* getAttributesTab(str information);
p_node addWordToTree(t_tree tree, str flechie, str non_flechie, str information);
int isNodeWord(p_node pn);
p_node findWordInTree(t_tree tree, str word);
p_node isWordInTree(t_tree tree, str word);
bform randomBaseFormInTree(t_tree t);
str combineStrSpaces(str* strTab, int nbStr);
cform* verifybaseform(bform forme,t_word mot);
void PrintdevCform(t_tree tree,str word);
void PrintCform(t_model model, t_tree nom,t_tree verbe,t_tree adj,t_tree adv);
bform* generateBasePhraseTab(t_tree verbs, t_tree nouns, t_tree adjectives, t_tree adverbs, t_model phrase);
str generateBasePhraseStr(t_tree verbs, t_tree nouns, t_tree adjectives, t_tree adverbs, t_model phrase);
int searchWordInTree(t_tree tree, str word);
cform* findCformInTree(t_tree tree, str word, t_tab* parcours, str* mot);
void searchCformInTrees( t_tree nom,t_tree verbe,t_tree adj,t_tree adv, str word);
cform* findCform(t_tree t,t_word mot);

#endif //PROJET_ALGO_L2_TREE_H
