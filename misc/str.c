//
// Created by a on 11/11/2022.
//

#include "str.h"

str createStrChar(char c){ //crée une str d'un seul caractère passé en argument
    str s = (str) malloc(2*sizeof(char));
    s[0] = c;
    s[1] = '\0';
    return s;
}

void addStrSize(str* dest, str addend){ //ajoute la string "addend" à la fin de "dest" de manière dynamique pour avoir
                                    // une taille logique égale à la taille physique
    // une taille logique égale à la taille physique
    str Newstr = (str) calloc(strlen(*dest) + strlen(addend) + 1,sizeof (char)); // +1 pour le '\0' car strlen() ne le compte pas
    strcat(Newstr,*dest);
    strcat(Newstr,addend);
    //free(*dest);
    *dest = Newstr;
}

void addStrChar(str* dest, char addend){ //ajoute le char "c" à la fin de "dest" en ajustant la taille physique
    addStrSize(dest, createStrChar(addend));
}

void addStrCharStart(str* dest, char addend){ //ajoute le char "c" au début de "dest" en ajustant la taille physique
    str Newstr = (str) calloc(strlen(*dest) + 2,sizeof (char));
    Newstr[0] = addend;
    for(int i=0 ; i< strlen(*dest);i++)
        Newstr[i+1] = (*dest)[i];
    *dest = Newstr;
}

