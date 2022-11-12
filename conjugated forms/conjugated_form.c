//
// Created by a on 10/11/2022.
//

#include "conjugated_form.h"

cform createCform(str *attributes, str non_flechie){
    cform formeFlechie;
    formeFlechie.attributes= attributes;
    formeFlechie.word=non_flechie;
    return formeFlechie;
}