//
// Created by a on 10/11/2022.
//

#include "conjugated_form.h"

/*
cform createCform(str ){

}
*/

str concatWordAttributes(t_word word){ //les attributs d'un mot sont un tableau de str :
                                // cette fonction renvoie les attributs d'un mot dans une seule séparés par des espaces
    str* SAttrib = word.attributes;
    int indexAttrib = 0;
    str currentWordAttrib = SAttrib[0];
    str concatAttribs;
    concatAttribs = (str) calloc(strlen(currentWordAttrib)+1,sizeof(char));

    int nbAttrib = 2;
    if(!strcmp(word.category,"nom"))
        nbAttrib = 2;
    else if(!strcmp(word.category,"verbe"))
        nbAttrib = 3;
    else if(!strcmp(word.category,"adverbe"))
        nbAttrib = 0;

    for(int i=0; i< nbAttrib; i++){
        if(indexAttrib != 0)
            addStrChar(&concatAttribs,' ');
        addStrSize(&concatAttribs,currentWordAttrib);
        indexAttrib++;
        currentWordAttrib = SAttrib[indexAttrib];
    }
    return  concatAttribs;
}

int compareWordWithCform(t_word word, cform form){ // compare une cform avec un mot : renvoie 1 si la cform a les mêmes
                                                    // attributs que le mot, 0 sinon
    str SAttrib = concatWordAttributes(word);
    int res = 0;
    for(int i=0; i < form.nbAttributes && res == 0 ; i++){
        if(!strcmp(form.attributes[i],SAttrib))
            res = 1;
    }
    return res;
}
cform createCform(str *attributes, str non_flechie, int nbAttributs){
    cform formeFlechie;
    formeFlechie.attributes = attributes;
    formeFlechie.word = non_flechie;
    formeFlechie.nbattributs = nbAttributs;
    return formeFlechie;
}