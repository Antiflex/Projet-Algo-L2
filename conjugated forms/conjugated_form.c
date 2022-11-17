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
    cform* formeFlechie = (cform*) malloc(sizeof(cform));
    formeFlechie->attributes = (str*) calloc(nbAttributs,sizeof(str*));
    copyAttributesTab(formeFlechie->attributes ,attributes,nbAttributs);
    formeFlechie->word = (str) calloc(strlen(flechie)+1,sizeof(char));
    strcpy(formeFlechie->word,flechie);
    formeFlechie->nbAttributes = nbAttributs;
    return formeFlechie;
}

void printDevCform(cform form){
    printf("%s : %d attribut(s) :\n",form.word,form.nbAttributes);
    for(int i = 0; i< form.nbAttributes; i++){
        printf("%s | ",form.attributes[i]);
    }
    printf("\n");
}

int* CountCategory(t_model t, str category){
    int* a=(int*) malloc(sizeof(strlen(t.words->category)));
    int j=0;
    for(int i=0;i< strlen((t.words->category));i++){
        if (!strcmp(t.words[i].category,category)){
            a[0]++;
            i=a[0];
            a[j]=i;
        }
    }
    return a;
}
void phraseconjugated(t_model t,t_tree nom,t_tree verbes,t_tree adjectifs,t_tree adverbes){
    int* nbnoms=CountCategory(t,"Nom");
    int* nbverbes= CountCategory(t,"Ver");
    int* nbadj= CountCategory(t,"Adj");
    int a=nbnoms[0]+nbverbes[0]+nbadj[0];
    bform b=randomBaseFormInTree(nom);
    str c="";
    str phrase =(str) malloc(sizeof(a));
    int i=1;
    while(nbnoms[0]!=0){
        c= verifybaseform(b,t);
        while(strlen(c)==0){
            b= randomBaseFormInTree(nom);
            c= verifybaseform(b,t);
        }
        printf("%s",c);
        nbnoms[0]--;
        i++;
    }
    i=1;
    while(nbverbes[0]!=0){
        c= verifybaseform(b,t);
        while(strlen(c)==0){
            b= randomBaseFormInTree(verbes);
            c= verifybaseform(b,t);
        }
        printf("%s",c);
        nbverbes[0]--;
        i++;
    }
    i=1;
    while(nbadj[0]!=0){

        c= verifybaseform(b,t);
        while(strlen(c)==0){
            b= randomBaseFormInTree(adjectifs);
            c= verifybaseform(b,t);
        }
        printf("%s",c);
        nbadj[0]--;
        i++;
    }


}
char* verifybaseform(bform base,t_model t){
    int a=base.node->nbForms;
    p_form_cell temp;
    int b=0;
    temp=base.node->forms.head;
    for(int i=0;i<a;i++){
        for(int j=0;j<strlen(*t.words[i].attributes);j++){
            b=b+(!strcmp(t.words[i].attributes[j],temp->value.attributes[i]));
        }
        if (b== strlen(*temp->value.attributes)){
            return temp->value.word;
        }
        temp=temp->next;
    }
    return "\0";
}