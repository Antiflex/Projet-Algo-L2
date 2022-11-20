//
// Created by a on 10/11/2022.
//

#include "conjugated_form.h"

void copyAttributesTab(str* dest, str* source, int nbAttributes){
    for(int i=0;i < nbAttributes; i++){
        dest[i] = (str) calloc(strlen(source[i])+1,sizeof(char));
        strcpy(dest[i],source[i]);
    }
}


cform* createCform(str *attributes, str flechie, int nbAttributs){
    cform* formeFlechie = (cform*) malloc(sizeof(cform));
    formeFlechie->attributes = (str*) calloc(nbAttributs,sizeof(str));
    copyAttributesTab(formeFlechie->attributes ,attributes,nbAttributs);
    formeFlechie->word = (str) calloc(strlen(flechie)+1,sizeof(char));
    strcpy(formeFlechie->word,flechie);
    formeFlechie->nbAttributes = nbAttributs;
    return formeFlechie;
}

void printDevCform(cform form){
    printf("%s : %d attribut(s) :\n",form.word,form.nbAttributes);
    for(int i = 0; i< form.nbAttributes; i++){
        printf("%s | ",form.attributes[i],form.attributes[i]);
    }
    printf("\n");
}

void printPrettyCform(cform form){
    printf("la forme flechie \"%s\" a %d homonyme(s) :\n",form.word,form.nbAttributes);
    for(int i = 0; i< form.nbAttributes; i++){
        printf("homonyme no %d : %s\n",i,form.attributes[i]);
    }
    printf("\n");
}
