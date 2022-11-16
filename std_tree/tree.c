//
// Created by Alexandre on 17/10/2022.
//

#include "tree.h"
#include <stdlib.h>
#include "function.h"

#define MAXATTLEN 20

p_node* createWordNodeTab(str word){ //crée un tableau de p_node qui, dans l'ordre, forment un mot,
    // les noeuds créés n'ont aucun lien de parenté
    int len = strlen(word);
    p_node* nodeTab = (p_node*) calloc(len,sizeof(p_node));
    for(int i=0; i<len; i++)
        nodeTab[i] = createNode(word[i]);

    return nodeTab;
}

p_node addWord(p_node current, str word){ // ajoute un mot (forme de base) à l'arbre à partir d'un noeud
    p_node temp = current;
    int i=1;
    while (i<strlen(word)){
        p_node IsChild = findChild(temp, word[i]); //on cherche si la 2ème lettre existe dans les enfants du noeud current
        if ( IsChild != NULL){
            //si la lettre existe :
            temp = IsChild;
        }
        else{ // problème ici
            printf("k\n");
            p_node new_child= createNode(word[i]);
            addChild(temp, new_child);
            temp = new_child;
        }
        i++;
    }
    return temp; //retourne la fin du mot /dernière lettre
}

str* splitStrColon(str string){ // renvoie une liste de str à partir d'une str qui utilise ':' comme séparateur
    int nbStr = isdeuxpoints(string)+1;
    str* tabStr = (str*) calloc(nbStr, sizeof(str));
    int strIndex = 0;
    for(int i =0; i<nbStr; i++){
        tabStr[i] = (str) calloc(MAXATTLEN, sizeof(char));
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
    printDevCform(*lastNodeForm);
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
    printf("[finding a : %s]\n",tree.nature);
    while (B){ //tant qu'on doit parcourir l'arbre
        printf("%u\n",current->children.head);
        int nextChildIndex = rand()%(current->children.childNb);
        // l'indice de la prochaine lettre est un nombre
        // aléatoire compris entre 0 et le nombre d'enfants de current
        p_child nextChild = current->children.head;
        for(int i=0; i<nextChildIndex; i++)
            nextChild = nextChild->next;
        current=nextChild->nodeValue; //current prend la valeur d'un de ses enfants au hasard

        addStrChar(&word,current->letter); // on ajoute la lettre de current a la str qui contient le mot formé
        printf("%c ",current->letter);
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
        printf("[word : %d]",i);
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
    printf("\n");
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