//
// Created by a on 11/11/2022.
//

#ifndef PROJET_ALGO_L2_MODEL_H
#define PROJET_ALGO_L2_MODEL_H

#include "str.h"
#define TEMPSNB 4

typedef struct s_word{ //structure d'un mot pour un modèle de phrase - similaire à celle des formes conjuguées, mais on stocke la catégorie du mot plutôt que le mot lui-même
    str category; //catégorie du mot (nom - verbe - ...) si c'est un mot prédéterminé alors la catégorie sera le mot lui-même, par example dans le modèle 2 : "qui"
    str* attributes; // attributs du mot, stockés non pas dans une seule str mais dans un tableau de str et il n'y a pas d'attribut invariable
}t_word;

typedef t_word* p_word;

typedef struct s_model { // structure d'un modèle de phrase
    t_word* words; //tableau de mots qui composent la phrase
    int* accords; // tableau des accords entre les mots (expliqué plus bas)
    int wordsNb; //nombre de mots dans la phrase
}t_model;

/*
 * Modèle n°1 : nom – adjectif – verbe – nom
 * Modèle n°2 : nom – ‘qui’ – verbe – verbe – nom – adjectif
 * Modèle n°3 :
 */

/* exemple : on veut faire le modèle 2 :
 mot0{
 category : "nom"
 attributes : [Genre , Nombre] déterminés au hasard dans ce cas
 }
 mot1{
 category : "qui"
 attributes : [Genre du mot0 , Nombre du mot0] // les attributs des mots prédéterminés sont une copie de ceux du mot avec lequel il s'accorde
                                                // dans tous les cas il aura un tableau de la forme [Genre, Nombre]
 }
 mot2{
 category : "verbe"
 attributes : [Temps, "SG" , "3"]    "SG" et "3" sont déterminés par l'accord avec le mot1 "qui" grâce à la fonction conjugate()
 }
 ...
 Model 2{
    Model2.words = {mot0, mot1, mot2, ...}
    Model2.accords = [ -1, 0, 1, 1, -1, 4]
    1er accord : -1 car le mot0 ne s'accorde avec aucun autre mot
    2eme accord : 0 car le mot1 s'accorde avec le mot0 (même s'il est invariable)
    3eme accord : 1 car le mot2 s'accorde avec le mot1
    4eme accord : 1 car le mot3 s'accorde avec le mot1
    ...
 }
*/

//prototypes

t_word createWord(str category);
void conjugate(t_word* word, t_word* accord);
t_model createModel(str* words, int* accords, int wordsNb);
void printDevModel(t_model model);
void conjugateModel(t_model model);
t_model createConjugatedModel(str* words, int* accords, int wordsNb);
t_model createRandomModel1();
t_model createRandomModel2();
t_model createRandomModel3();


#endif //PROJET_ALGO_L2_MODEL_H