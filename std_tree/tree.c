//
// Created by Alexandre on 17/10/2022.
//

#include "tree.h"
#include <stdlib.h>


p_node* createWordNodeTab(str word){ //crée un tableau de p_node qui, dans l'ordre, forment un mot,
                                    // les noeuds créés n'ont aucun lien de parenté
    int len = strlen(word);
    p_node* nodeTab = (p_node*) calloc(len,sizeof(p_node));
    for(int i=0; i<len; i++)
        nodeTab[i] = createNode(word[i]);

    return nodeTab;
}

void addWord(t_tree* t, str word){ // ajoute un mot (forme de base) à l'arbre
    p_node* nodeTab = createWordNodeTab(word);
    int len = strlen(word);
    p_node current = t->root;
    for(int i=0; i<len; i++){
        return;
    }
    return;
}

// 4

int isNodeWord(p_node pn){
    return pn->nbForms > 0;
}

p_node findWordInTree(t_tree t, str word){ // recherche si le mot "word" est une suite de lettres présentes dans l'arbre "t"
                                            // retourne le noeud de la dernière lettre si trouvé, NULL sinon
    p_node temp = t.root;
    int i = 0; // index de la lettre du mot qu'on recherche
    while(temp!=NULL && word[i] != '\0'){       // tant qu'on n'est pas arrivé à la dernière du mot et qu'on a trouvé
                                                // le noeud de la lettre précédente à rechercher alors :
        temp = findChild(temp, word[i]);    // on cherche la i-ème lettre du mot dans les enfants du (i-1)-ème
        i++;                                         // noeud puis i++;
    }
    if(temp == NULL){ //si on a trouvé toutes les lettres de "word" jusqu'à la dernière alors :

        return temp;     //on retourne le pointeur vers la dernière lettre du mot
    }
    else                 //sinon on retourne NULL
        return NULL;
}

p_node IsWordInTree(t_tree t, str word){//recherche si le mot "word" est une forme de word présente dans l'arbre "t"
    p_node last = findWordInTree(t, word); // cherche la suite de lettre "word" dans l'arbre
    if(last != NULL && isNodeWord(last)) // si le mot "word" est trouvé et qu'il représente la forme de base d'un mot
        return last;                              // on retourne le p_node de la dernière lettre du mot
    else
        return NULL;                              // sinon on retourne NULL
}

bform randomBaseFormInTree(t_tree t){ //retourne une forme de base aléatoire présente dans l'arbre "t"
    // toutes les feuilles de l'arbre représentent une forme de base donc il n'y a aucun cas de parcours de l'arbre qui
    // ne fini pas à un mot, cependant tous les mots sont pas forcément des feuilles donc il ne faut pas les ignorer

    p_node current = t.root;
    int B = 1; //booléen qui décide quand on arrête de parcourir l'arbre (à 1 on continue, à 0 on arrête)
    str word = (str) malloc(sizeof(char));
    word[0]='\0'; // initialisation de la str qui va contenir le mot que l'on obtient en parcourant l'arbre

    while (B){ //tant qu'on doit parcourir l'arbre

        int nextChildIndex = rand()%(current->children.childNb + 1);
        // l'indice de la prochaine lettre est un nombre
        // aléatoire compris entre 0 et le nombre d'enfants de current
        p_child nextChild = current->children.head;
        for(int i=0; i<nextChildIndex; i++)
            nextChild = nextChild->next;

        addStrChar(word,current->letter);

        if(nextChild->nodeValue->children.childNb == 0) // si le noeud est une feuille alors on s'arrête là
            B = 0;
        else{
            int randFactor = 2;  //sinon alors on a une chance sur randFactor de s'arrêter
            B = rand()%randFactor; // B prend une valeur entre 0 et randFactor-1
            B = (B!=0); // si B est différent de 0 alors B prend 1 (= on continue) sinon B est égale à 0 et on s'arrête
        }
    }
    bform result;
    result.word = word;
    result.node = current;
    return result;
}