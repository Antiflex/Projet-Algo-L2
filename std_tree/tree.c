//
// Created by Alexandre on 17/10/2022.
//

#include "tree.h"
#include <stdlib.h>
#include "function.h"

#define MAX 20



str* splitStrColon(str string){ // renvoie une liste de str à partir d'une str qui utilise ':' comme séparateur
    int nbStr = isdeuxpoints(string)+1;
    str* tabStr = (str*) calloc(nbStr, sizeof(str));
    int strIndex = 0;
    for(int i =0; i<nbStr; i++){
        tabStr[i] = (str) calloc(MAX,sizeof(char));
        strIndex = deuxpoints(string,tabStr[i],strIndex)+1;
        tabStr[i] = realloc(tabStr[i],(strlen(tabStr[i])+1)*sizeof(char));
    }
    return tabStr;
}

str* getAttributesTab(str information){ //retourne un tableau d'attributs utilisables dans une cform
    int nbAtt = isdeuxpoints(information);
    str * attTab = (str*) calloc(nbAtt,sizeof(str));
    str* tab = splitStrColon(information);
    for(int i=0; i<nbAtt; i++){
        attTab[i] = tab[i+1];
        isplus(attTab[i]);
    }
    free(tab);
    return attTab;
}


p_node addWordToTree(t_tree tree,str flechie, str non_flechie, str information){
    int nbAttributes = isdeuxpoints(information);
    str* attributes = getAttributesTab(information);
    p_node currentLetterNode = tree.root;
    for(int i=0; non_flechie[i] !='\0'; i++){
        p_node newNode = findChild(currentLetterNode,non_flechie[i]);// on cherche la lettre suivante dans les enfants de current
        if(newNode == NULL) { // si on ne la trouve pas on crée un p_node avec cette lettre et l'ajoute aux enfants de current
            newNode = createNode(non_flechie[i]);
            addChild(currentLetterNode, newNode);
        }
        currentLetterNode = newNode; //on se déplace dans l'enfant pour ensuite répéter
    }
    cform* lastNodeForm = createCform(attributes,flechie,nbAttributes);
    //print :
    //printf("\n%u\n[1]",currentLetterNode);
    //printDevCform(*lastNodeForm);
    p_form_cell newFormCell = createCell(lastNodeForm);
    addHeadList(&currentLetterNode->forms,newFormCell);
    currentLetterNode->nbForms++;
    return currentLetterNode;
}

t_tree createEmptyTree(char class_gram[]){ // crée un arbre avec un noeud root qui a pour valeur ' '
    t_tree T;
    T.root = createNode('0');
    T.nature= class_gram;
    return T;
}


int isNodeWord(p_node pn){
    if(pn == NULL)
        return 1;
    return pn->nbForms > 0;
}

p_node findWordInTree(t_tree tree, str word){ // recherche si le mot "word" est une suite de lettres présentes dans l'arbre "tree"
    // retourne le noeud de la dernière lettre si trouvé, NULL sinon
    p_node temp = tree.root;
    int i = 0; // index de la lettre du mot qu'on recherche
    while(temp!=NULL && word[i] != '\0'){       // tant qu'on n'est pas arrivé à la dernière du mot et qu'on a trouvé
        // le noeud de la lettre précédente à rechercher alors :
        temp = findChild(temp, word[i]);    // on cherche la i-ème lettre du mot dans les enfants du (i-1)-ème
        i++;                                         // noeud puis i++;
    }
    if(temp != NULL){ //si on a trouvé toutes les lettres de "word" jusqu'à la dernière alors :

        return temp;     //on retourne le pointeur vers la dernière lettre du mot
    }
    else                 //sinon on retourne NULL
        return NULL;
}

p_node isWordInTree(t_tree tree, str word){//recherche si le mot "word" est une forme de word présente dans l'arbre "tree"
    p_node last = findWordInTree(tree, word); // cherche la suite de lettre "word" dans l'arbre
    if(last != NULL && isNodeWord(last)) // si le mot "word" est trouvé et qu'il représente la forme de base d'un mot
        return last;                              // on retourne le p_node de la dernière lettre du mot
    else
        return NULL;                              // sinon on retourne NULL
}

int searchWordInTree(t_tree tree, str word){//retourne 1 si le mot existe
    p_node pn = isWordInTree(tree, word);
    if(pn!=NULL)
        printf("le mot \"%s\" est present dans l'abre des %s\n",word,tree.nature);
    else
        printf("le mot \"%s\" est absent de l'arbre des %s\n",word,tree.nature);
    return(pn != NULL);
}

bform randomBaseFormInTree(t_tree tree){ //retourne une forme de base aléatoire présente dans l'arbre "t"
    // toutes les feuilles de l'arbre représentent une forme de base donc il n'y a aucun cas de parcours de l'arbre qui
    // ne fini pas à un mot, cependant tous les mots sont pas forcément des feuilles donc il ne faut pas les ignorer
    if(tree.root->children.childNb == 0)
        return;
    p_node current = tree.root;
    int B = 1; //booléen qui décide quand on arrête de parcourir l'arbre (à 1 on continue, à 0 on arrête)
    str word = (str) malloc(sizeof(char));
    word[0]='\0'; // initialisation de la str qui va contenir le mot que l'on obtient en parcourant l'arbre

    while (B){ //tant qu'on doit parcourir l'arbre
        int nextChildIndex = rand()%(current->children.childNb);
        // l'indice de la prochaine lettre est un nombre
        // aléatoire compris entre 0 et le nombre d'enfants de current
        p_child nextChild = current->children.head;
        for(int i=0; i<nextChildIndex; i++)
            nextChild = nextChild->next;
        current=nextChild->nodeValue; //current prend la valeur d'un de ses enfants au hasard

        addStrChar(&word,current->letter); // on ajoute la lettre de current a la str qui contient le mot formé

        if(current->children.childNb == 0) // si le noeud est une feuille alors on s'arrête là
            B = 0;
        else if(isNodeWord(current)){ // sinon si le noeud qu'on regarde est un mot alors :
            int randFactor = rand()%2 +2;   //on a une chance sur randFactor de s'arrêter :
            B = rand()%randFactor; // B prend une valeur entre 0 et randFactor-1
            B = (B!=0); // si B est différent de 0 alors B prend 1 (= on continue) sinon B est égale à 0 et on s'arrête
        }
    }
    bform result;
    result.word = word;
    result.node = current;
    return result;
}

//génération de phrase avec des formes de base


bform* generateBasePhraseTab(t_tree verbs, t_tree nouns, t_tree adjectives, t_tree adverbs, t_model phrase){ //retourne une liste de bform aléatoires selon le model
    bform* bformTab = (bform*) calloc(phrase.wordsNb,sizeof(bform));
    for(int i=0; i<phrase.wordsNb; i++){
        t_word currentWord = phrase.words[i];
        str currentCategory = currentWord.category;
        if(!strcmp(currentCategory,"nom")){
            bformTab[i] = randomBaseFormInTree(nouns);
        }
        else if(!strcmp(currentCategory,"verbe")){
            bformTab[i] = randomBaseFormInTree(verbs);
        }
        else if(!strcmp(currentCategory,"adjectif")){
            bformTab[i] = randomBaseFormInTree(adjectives);
        }
        else if(!strcmp(currentCategory,"adverbe")){
            bformTab[i] = randomBaseFormInTree(adverbs);
        }
        else{
            bformTab[i].word = currentWord.category;
            bformTab[i].node = NULL;
        }
    }
    return bformTab;
}

str generateBasePhraseStr(t_tree verbs, t_tree nouns, t_tree adjectives, t_tree adverbs, t_model phrase){ //même fonction mais renvoie un str
    str phraseStr = malloc(sizeof(char));
    phraseStr[0] = '\0';
    bform* bformTab = generateBasePhraseTab(verbs,nouns, adjectives, adverbs, phrase);
    for(int i=0; i<phrase.wordsNb; i++){
        addStrSize(&phraseStr,bformTab[i].word);
        addStrSize(&phraseStr," ");
    }
    return phraseStr;
}


cform* verifybaseform(bform forme,t_word mot){
    int nbStr = 2;
    str category = mot.category;
    if(!strcmp(category,"verbe")){
        if(!strcmp(mot.attributes[0],"Inf"))
            nbStr = 1;
        else
            nbStr = 3;
    }
    str attributmot= combineStrSpaces(mot.attributes,nbStr );
    p_form_cell temp=forme.node->forms.head;
    for(int i=0;i<forme.node->nbForms;i++){
        for(int j=0; j<temp->value->nbAttributes; j++) {
            if (!strcmp(temp->value->attributes[j], attributmot)) {
                return temp->value;
            }
        }
        temp=temp->next;
    }
    return NULL;
}
str combineStrSpaces(str* strTab, int nbStr){ // combine les str contenues dans un tableau en une seule str avec un espace comme séparateur
    str Newstr = (str) malloc(sizeof(char));
    Newstr[0]= '\0';
    for(int i = 0; i<nbStr; i++){
        addStrSize(&Newstr,strTab[i]);
        if (i != nbStr-1)
            addStrChar(&Newstr,' ');
    }
    return  Newstr;
}

cform* findCform(t_tree t,t_word mot){
    int cpt=0;
    bform base;
    do{
        base= randomBaseFormInTree(t);
        cform* c=verifybaseform(base,mot);
        if(c!=NULL){
            return c;
        }
        cpt++;
    }while(cpt!=400);
    return NULL;
}

void PrintCform(t_model model, t_tree nom,t_tree verbe,t_tree adj,t_tree adv){
    for(int i=0;i<model.wordsNb;i++){
        if(!strcmp(model.words[i].category,"nom")){
            // on affiche un déterminant avant le nom
            int defini = 0;
            if(rand()%2)
                defini = 1;
            if(!strcmp(model.words[i].attributes[1],"PL")){
                if(defini)
                    printf("les ");
                else
                    printf("des ");
            }
            else{
                if(!strcmp(model.words[i].attributes[0],"Mas")) {
                    if(defini)
                        printf("le ");
                    else
                        printf("un ");
                }
                else{
                    if(defini)
                        printf("la ");
                    else
                        printf("une ");
                }
            }
            printf("%s ",findCform(nom,model.words[i])->word);
        }else if(!strcmp(model.words[i].category,"verbe")){
            printf("%s ",findCform(verbe,model.words[i])->word);
        }else if(!strcmp(model.words[i].category,"adjectif")){
            printf("%s ",findCform(adj,model.words[i])->word);
        }else if(!strcmp(model.words[i].category,"adverbe")){
            printf("%s ",findCform(adv,model.words[i])->word);
        }else{
            printf("%s ",model.words[i].category);
        }
    }
}

cform* findCformInTree(t_tree tree, str word, t_tab* parcours, str* mot){
    p_node pn = findNodeCform(tree.root,word,parcours,mot);

    cform* res = NULL;
    if(pn != NULL) { //forme fléchie trouvée :
        p_node temp = tree.root;
        for (int i = 0; i < parcours->len; i++) {
            p_child child = temp->children.head;
            for (int j = 0; j < parcours->tab[i]; j++) {
                child = child->next;
            }
            temp = child->nodeValue;
        }
        res = searchCformInList(temp->forms,temp->nbForms,word);
        //affichage des résultats :
    }
    return res;
}

void searchCformInTrees( t_tree noms,t_tree verbes,t_tree adjectifs,t_tree adverbes, str word){
    int found = 0;
    t_tree ordre[4]= {noms,verbes,adjectifs,adverbes};
    str ordreStr[4]= {"nom","verbe","adjectif","adverbe"};
    for(int i=0; i<4;i++) {


        str* mot = malloc(sizeof(str));
        *mot = calloc(1,sizeof(char));
        (*mot)[0] = '\0';

        p_tab parcours = malloc(sizeof(t_tab));
        parcours->len = 0;

        cform* res = findCformInTree(ordre[i], word, parcours, mot);

        if(res != NULL){
            found = 1;
            printf("\nle mot \"%s\" existe en tant que %s :\n",word,ordreStr[i]);
            printf("c'est une forme flechie de %s:\n",*mot);
            printPrettyCform(*res);
            printf("\n");
        }

        free(mot);
        free(parcours);
    }
    if(found==0)
        printf("\nle mot \"%s\" n'a pas ete trouve\n",word);
}