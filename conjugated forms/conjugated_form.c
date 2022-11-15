//
// Created by a on 10/11/2022.
//

#include "conjugated_form.h"

void copyAttributesTab(str* dest, str* source, int nbAttributes){
    for(int i=0;i < nbAttributes; i++){
        str currentAtt = (str) calloc(strlen(source[i])+1,sizeof(char));
        strcpy(currentAtt,source[i]);
        dest[i] = currentAtt;
    }
}



cform* createCform(str *attributes, str flechie, int nbAttributs){
    cform* formeFlechie = malloc(sizeof(cform));
    formeFlechie->attributes = (str*) malloc(sizeof(str*));
    copyAttributesTab(formeFlechie->attributes ,attributes,nbAttributs);
    formeFlechie->word = (str) calloc(strlen(flechie)+1,sizeof(char));
    strcpy(formeFlechie->word,flechie);
    formeFlechie->nbattributs = nbAttributs;
    return formeFlechie;
}

void printDevCform(cform form){
    printf("%s : %d attribute(s) :\n",form.word,form.nbattributs);
    for(int i = 0; i< form.nbattributs; i++){
        printf("%s | ",form.attributes[i]);
    }
    printf("\n");
}