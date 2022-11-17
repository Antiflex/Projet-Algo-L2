//
// Created by a on 10/11/2022.
//

#ifndef PROJET_ALGO_L2_CONJUGATED_FORM_H
#define PROJET_ALGO_L2_CONJUGATED_FORM_H

#include <stdlib.h>
#include "stdio.h"
#include "model.h"
#include "str.h"
#include "tree.h"
#include "node.h"
#include "model.h"
typedef char* str;

typedef struct { // structure d'une forme fléchie
    str word; //mot de la forme fléchie
    str* attributes; //attributs de la forme fléchie :
    int nbAttributes; // nombres d'attributs
}cform;
    /*
     * les attributs sont dans un tableau de str qui sont expliqués sur moodle
     * les str stockent tous les attributs d'une forme fléchie séparés par des espaces
     * ils sont stockés dans le même ordre :
     * pour les noms :
     * 1) le genre (Mas - Fem - InvGen)
     * 2) le nombre (SG - PL)
     * pour les adjectifs : pareil
     * pour les verbes :
     * 1) le temps (Inf - IPre - IImp - SPre - PPas) ( IXx : indicatif , SXx : subjonctif , PXx participe ..)
     * 2) le nombre de la personne (SG - PL)
     * 3) le numéro de la personne (1 - 2 - 3)
     * pour les adverbes :
     * 1) un champ invariable (Adv)
     *
     *ex : on veut stocker la forme fléchie de :
     *
     * abacule	abacule	Nom:Mas+SG
     * alors on aura
     *
     * cform forme1{
     *  forme1.word = "abacule"
     *  forme1.attributes = ["Mas SG"]
     * }
     *
     *pour la forme fléchie de :
     *
     * abaissais	abaisser	Ver:IImp+SG+P1:IImp+SG+P2
     * on a
     *
     * cform forme2{
     *  forme2.word = "abaissais"
     *  forme2.attributes = ["IImp SG P1","IImp SG P2"]
     * }
     */

//prototypes
void copyAttributesTab(str* dest, str* source, int nbAttributes);
cform* createCform(str *attributes, str flechie, int nbAttributs);
void printDevCform(cform form);
cform* createCform(str *attributes, str non_flechie, int nbAttributs);
int* CountCategory(t_model t, str category);
char* verifybaseform(bform base,t_model t);
void phraseconjugated(t_model t,t_tree nom,t_tree verbes,t_tree adjectifs,t_tree adverbes);
str concatWordAttributes(t_word word);
int compareWordWithCform(t_word word, cform form);

#endif //PROJET_ALGO_L2_CONJUGATED_FORM_H
