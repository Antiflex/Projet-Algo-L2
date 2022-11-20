//
// Created by Alexandre on 17/10/2022.
//

#include "form_list.h"

void addHeadList(form_list* list, p_form_cell pc){ //chaine un form_cell en tete de la liste des conjugated forms
        p_form_cell temp = list->head;
        list->head = pc;
        pc->next = temp;
}


cform* searchCformInList(form_list list, int nbforms, str word){ //retoune la cform cherchée si le mot "word" est une forme fléchie dans la liste "list"
    if(nbforms >0){
        p_form_cell temp = list.head;
        for (int i = 0; i<nbforms;i++){
            if(!strcmp(temp->value->word,word)) {
                return temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }
    else
        return NULL;
}