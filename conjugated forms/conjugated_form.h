//
// Created by a on 10/11/2022.
//

#ifndef PROJET_ALGO_L2_CONJUGATED_FORM_H
#define PROJET_ALGO_L2_CONJUGATED_FORM_H

#include <stdlib.h>
#include <string.h>
typedef char* str;

typedef struct { // structure d'une forme fléchie
    str word; //mot de la forme fléchie
    str* attributes; //attributs de la forme fléchie :
    /*
     * les attributs sont dans un tableau de str qui sont expliqués sur moodle
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
     */
}cform;

//prototypes

#endif //PROJET_ALGO_L2_CONJUGATED_FORM_H
