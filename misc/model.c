//
// Created by a on 11/11/2022.
//

#include "model.h"

t_word createWord(str category){ // crée un mot : si c'est un nom alors le genre et le nombre sont aléatoire
                                            // si c'est un verbe alors le temps est aléatoire
    t_word result;
    result.category = category;
    //nom
    str Genre[] = {"Mas", "Fem"};
    str Nombre[] = {"SG", "PL"};
    //verbe
    str Temps[TEMPSNB] = {"Inf","IPre","IImp","SPre"};
    if(strcmp(category,"nom")==0){
        result.attributes = (str*) calloc(2,sizeof(str));
        int genre = rand()%2;
        int nombre = rand()%2;
        result.attributes[0] = Genre[genre];
        result.attributes[1] = Nombre[nombre];
    }
    else if(strcmp(category,"verbe")==0){
        result.attributes = (str*) calloc(3,sizeof(str));
        int temps = rand()%TEMPSNB;
        result.attributes[0] = Temps[temps];
        result.attributes[2] = "3";
    }
    else{
        result.attributes = (str*) calloc(2,sizeof(str));
    }
    return result;
}

void conjugate(t_word* word, t_word* accord){ // modifie le mot "word" pour l'accorder avec le mot "accord"
    if(word->category == "nom") //si le mot à accorder est un nom alors on ne fait rien
        return;
    else if(!strcmp(word->category, "adjectif")) //un adjectif s'accorde avec un nom ou un mot prédéterminé donc il aura les mêmes attributs
        word->attributes = accord->attributes;
    else if(!strcmp(word->category, "verbe")) { // un verbe s'accorde en nombre avec le sujet qui est un nom ou un mot prédéterminé
        word->attributes[1] = accord->attributes[1];
        word->attributes[3] = "3";
    }
    else
        word->attributes = accord->attributes;
}

t_model createModel(str* words, int* accords, int wordsNb){ // crée une modèle de phrase selon les mots, accords et le nb de mots en arguments
    t_model model;
    model.words = (t_word*) calloc(wordsNb,sizeof(t_word));
    for (int i=0; i<wordsNb; i++){
        model.words[i] = createWord(words[i]);
    }
    model.accords = accords;
    model.wordsNb = wordsNb;
    return model;
}

void printDevModel(t_model model){ // fonction pour visualiser le modèle d'une phrase
    for(int i=0; i<model.wordsNb; i++){
        printf("[%s : %d : ",model.words[i].category, model.accords[i]);
        int attNb = 2;
        if(!strcmp(model.words[i].category,"verbe"))
            attNb = 3;
        else if(!strcmp(model.words[i].category,"adverbe"))
            attNb = 0;
        for(int j=0; j<attNb; j++)
            printf(" %s :", model.words[i].attributes[j]);
        printf("]");
    }
    printf("\n");
}

void conjugateModel(t_model model){ //conjugue tous les mots du model entre eux selon le tableau des accords
    for(int i = 0;i<model.wordsNb;i++){
        conjugate(&model.words[i],&model.words[model.accords[i]]);
    }
}

//Modèle n°1 : nom – adjectif – verbe – nom
str model1str[4] = {"nom","adjectif","verbe","nom"};
int model1accords[4] = {-1, 0, 0, -1};

//Modèle n°2 : nom – ‘qui’ – verbe – verbe – nom – adjectif
str model2str[6] = {"nom","qui","verbe","verbe","nom","adjectif"};
int model2accords[6] = {-1, 0, 1, 1, -1, 4};

//Modèle n°3 :

t_model createConjugatedModel(str* words, int* accords, int wordsNb){
    t_model model = createModel(words,accords,wordsNb);
    conjugateModel(model);
    return model;
}

t_model createRandomModel1(){
    return createConjugatedModel(model1str,model1accords,4);
}

t_model createRandomModel2(){
    return createConjugatedModel(model2str,model2accords,6);
}

t_model createRandomModel3(){
    return createConjugatedModel(model2str,model2accords,6);
}
