//
// Created by basti_27sky4h on 25/10/2022.
//

#include "function.h"
int isdeuxpoints(char* v1){/**On compte le nombre de deux points dans v1 puis on le retourne*/
    int i=0;
    int j=0;
    while(v1[i]!='\0'){
        if (v1[i]==':'){
            j++;
        }
        i++;
    }
    return j;
}
int deuxpoints(char* v1,char* v2, int i){/**On implémente les caractères contenus dans v1 à partir de l'indice i dans v2 jusqu'à rencontrer deux points ou \0*/
    int j=i;
    int k=0;
    while((v1[j]!='\0') && (v1[j]!=':')){
        v2[k]=v1[j];
        k++;
        j++;
    }
    return j;
}
void isplus(char* v1){/**On remplace les plus contenus dans v1 par des espaces */
    int i=0;
    while(v1[i]!='\0'){
        if (v1[i]=='+'){
            v1[i]=' ';
        }
        i++;
    }
}
void Emptystr(char* v1){/**On vide v1*/
    int i = strlen(v1);
    for(int j = 0;j<i;j++){
        v1[j]=' ';
    }
}

