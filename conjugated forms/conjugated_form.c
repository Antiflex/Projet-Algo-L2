//
// Created by a on 10/11/2022.
//

#include "conjugated_form.h"

cform createCform(str *attributes, str non_flechie, int nbAttributs){
    cform formeFlechie;
    formeFlechie.attributes= attributes;
    formeFlechie.word=non_flechie;
    formeFlechie.nbattributs = nbAttributs;
    return formeFlechie;
}