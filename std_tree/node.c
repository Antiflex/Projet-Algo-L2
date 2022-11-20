//
// Created by Alexandre on 17/10/2022.
//

#include "node.h"
#include <stdlib.h>

p_node createNode(char letter){ // crée un noeud de l'arbre dont la lettre est en paramètre
    p_node pn = (p_node) malloc(sizeof (t_node));
    pn->letter = letter;

    pn->children.head = NULL;
    pn->children.childNb = 0;

    pn->forms.head = NULL;
    pn->nbForms = 0;
    pn->children.head=NULL;
    pn->children.childNb=0;
    return pn;
}

p_child createChild(p_node pn){ // crée un maillon enfant : un maillon qui a pour valeur un p_node
    p_child pc = (p_child) malloc(sizeof(t_child));
    pc->nodeValue = pn;
    pc->next = NULL;
    return pc;
}

void addConjForm(p_node pn, cform form){ // ajoute un mot (forme de type cform) à la liste des conjugated forms d'un noeud
    pn->nbForms++;
    p_form_cell pc = createCell(&form);
    addHeadList(&pn->forms,pc);
}

p_node findChild(p_node pn, char letter){ // cherche un p_node dans la liste des enfants de pn dont la lettre est "letter"
                                            // retourne le p_node si trouvé, NULL sinon
    p_child current = pn->children.head;
    while(current != NULL && current->nodeValue->letter != letter){
        current = current->next;
    }
    if (current == NULL)
        return  NULL;
    return current->nodeValue;
}

void addChild(p_node pn, p_node childNode){ // ajoute un enfant dans la liste des enfants de pn
    p_child newChild = createChild(childNode);
    if(pn->children.head != NULL){ //la liste n'est pas vide / le noeud possède des enfants
        p_child temp = pn->children.head;
        pn->children.head = newChild;
        newChild->next = temp;
    }
    else{ //la liste est vide / le noeud ne possède pas d'enfant
        pn->children.head = newChild;
    }
    pn->children.childNb++;
}

p_node findNode(p_node pn, char c) { //  Pas utile mais elle reste symboliquement pour le temps passer à la réaliser TT
    p_node temp1 = NULL;
    p_node temp2 = pn;
    p_child temp3= pn->children.head;
    temp1 = findChild(pn, c);
    while (temp1 == NULL && temp3 != NULL) {
        temp1 = findChild(temp3->nodeValue, c);    // on cherche si la lettre est dans les enfants de pn
        if (temp3->next != NULL)
            temp3=temp3->next;
        else{
            temp1=findNode(temp2->children.head->nodeValue, c);
            if (temp1 == NULL)
                temp1=findNode(temp3->nodeValue, c);
        }
    }
    return temp1;
}

void addIntToStart(t_tab* tab, int val){ //ajoute "val" au début du tableau tab
    int* newtab = calloc(tab->len +1,sizeof (int));
    for(int i=0; i<tab->len ;i++) {
        newtab[i + 1] = tab->tab[i];
    }
    tab->len++;
    newtab[0] = val;
    (*tab).tab = newtab;
}

p_node findNodeCform(p_node pn, str word, t_tab* parcours, str* wordRes){ //recherche l'existence d'une forme fléchie "word" dans un p_node et ses enfants
    //parcours est un pointeur vers le tableau qui représentera les parcours des enfants
    //wordRes est un pointeur vers la forme de base qui contient la forme fléchie qu'on recherche
    p_node res = NULL;
    if(pn == NULL)
        res = NULL;
    else{// on recherche parmis les cforms du p_node passé en paramètres s'il existe une cform dont le mot est "word"
        form_list formList = pn->forms;
        int nbforms = pn->nbForms;
        cform* currentNodeForm = searchCformInList(formList,nbforms,word);
        if(currentNodeForm != NULL)
            res = pn; //si le mot recherché est parmi les cform de "pn" alors on retourne "pn"
        else{ //sinon on recherche parmi ses enfants
            if(pn->children.childNb > 0) { //s'il a des enfants alors on les parcourt et lance la même recherche parmi eux
                p_child child = pn->children.head;
                for (int i = 0; i < pn->children.childNb; i++) {
                    form_list list = child->nodeValue->forms;
                    if(findNodeCform(child->nodeValue,word,parcours,wordRes) != NULL) { // si parmi les enfants on a resultat non NULL alors ce sera notre resultat
                        res = child->nodeValue; // on doit aussi ajouter le numéro de l'enfant au tableau du parcours et la lettre au mot resultant
                        addIntToStart(parcours,i);
                        printf("%d : ",i);
                    }
                    child = child->next;
                }
            }
            else
                res = NULL; // si le p_node n'a pas d'enfants alors on retourne NULL puisqu'on a rien trouvé
        }
    }
    if(res!=NULL)
        printf("%u:%c\n",res,pn->letter);
    return res;
}