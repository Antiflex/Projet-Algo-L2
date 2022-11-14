//
// Created by Alexandre on 17/10/2022.
//

#include "tree.h"
#include <stdlib.h>
#include "function.h"
#define MAX 10

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
        attTab[i] =tab[i+1];
        isplus(attTab[i]);
    }
    free(tab);
    return attTab;
}


p_node addWordToTree(t_tree tree,str flechie, str non_flechie, str information){
    int nbAttributes = isdeuxpoints(information);
    str* attributes = getAttributesTab(information);
    p_node currentLetterNode = tree.root;
    for(int i=0; non_flechie[i] !=0; i++){
        p_node newNode = findChild(currentLetterNode,non_flechie[i]);// on cherche la lettre suivante dans les enfants de current
        if(newNode == NULL) { // si on ne la trouve pas on crée un p_node avec cette lettre et l'ajoute aux enfants de current
            newNode = createNode(non_flechie[i]);
            addChild(currentLetterNode, newNode);
        }
        currentLetterNode = newNode; //on se déplace dans l'enfant pour ensuite répéter
    }
    cform lastNodeForm = createCform(attributes,flechie,nbAttributes);
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

/* t_tree createTree(char *TypeOfWord){ // ajouter d'autre argument pour utiliser les fonctions de Bastien
    t_tree T;
    T.nature = TypeOfWord;
    //forme de base, fléchie, genre, nombre... de la ligne 1 du dico à récupérer avec les fonctions de bastien
    char BaseForm1[]= ;
    char FlexForm1[]= ;
    char *Parameters1[]= ;

    //forme de base, fléchie, genre, nombre... de la ligne 2 du dico
    char BaseForm2[]= ;
    char FlexForm2[]= ;
    char *Parameters2[]= ;

    //On ajoute le premier mot du dico
    T.root= createNode(BaseForm1[0]);
    p_node StartLetter = T.root; //la lettre du début de notre mot
    p_node EndLetter = addWord(StartLetter, BaseForm1); //la lettre de la fin de notre mot
    addConjForm(EndLetter, createCform(FlexForm1, Parameters1)); // on ajoute la forme fléchie

    //Boucle pour ajouter le reste de notre dico à m'arbre
    while ( ){ //temps qu'on  a pas parcouru tout le dico
        if (BaseForm1 == BaseForm2){
            addConjForm(EndLetter, createCform(FlexForm2, Parameters2));
        }
        else{
            //trouver un noeud où ajouter la nouvelle forme de base
            //vérifier pour les enfants du premier noeud
        }

    }
}*/

int isNodeWord(p_node pn){
    return pn->nbForms > 0;
}

p_node findWordInTree(t_tree t, str word){ // recherche si le mot "word" est une suite de lettres présentes dans l'arbre "t"
    // retourne le noeud de la dernière lettre si trouvé, NULL sinon
    p_node temp = t.root;
    int i = 0; // index de la lettre du mot qu'on recherche
    while(temp!=NULL && word[i] != '\0'){       // tant qu'on n'est pas arrivé à la dernière du mot et qu'on a trouvé
        // le noeud de la lettre précédente à rechercher alors :
        temp = findChild(temp, word[i]);// on cherche la i-ème lettre du mot dans les enfants du (i-1)-ème
        i++;                                         // noeud puis i++;
    }
    if(temp != NULL){ //si on a trouvé toutes les lettres de "word" jusqu'à la dernière alors :

        return temp;     //on retourne le pointeur vers la dernière lettre du mot
    }
    else                 //sinon on retourne NULL
        return NULL;
}

p_node isWordInTree(t_tree t, str word){//recherche si le mot "word" est une forme de word présente dans l'arbre "t"
    p_node last = findWordInTree(t, word); // cherche la suite de lettre "word" dans l'arbre
    if(last != NULL && isNodeWord(last)) // si le mot "word" est trouvé et qu'il représente la forme de base d'un mot
        return last;                              // on retourne le p_node de la dernière lettre du mot
    else
        return NULL;                              // sinon on retourne NULL
}
