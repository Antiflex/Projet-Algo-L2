//
// Created by basti_27sky4h on 25/10/2022.
//

#include "function.h"
int isdeuxpoints(char* v1){
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
int deuxpoints(char* v1,char* v2, int i){
    int j=i;
    int k=0;
    while((v1[j]!='\0') && (v1[j]!=':')){
        v2[k]=v1[j];
        k++;
        j++;
    }
    return j;
}
void isplus(char* v1){
    int i=0;
    while(v1[i]!='\0'){
        if (v1[i]=='+'){
            v1[i]=' ';
        }
        i++;
    }
}
