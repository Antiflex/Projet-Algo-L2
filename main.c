//
// Created by Alexandre on 17/10/2022.
//
#include <stdio.h>
#include "tree.h"
#include <time.h>

int main(){
    time_t time1;
    srand(515534*time(&time1));
    printf("a\n");
    /*
    str s = createStrChar('a');
    addStrChar(s,'b');
    str t = createStrChar('c');
    addStrChar(t,'d');
    addStrSize(s,t);
    printf("%s",s);
    */
    /*
    int B;
    int n = 1000;
    int randFactor = 3;
    int count=0;
    for(int i=0; i<n;i++) {
        B = rand() % randFactor;
        B = (B != 0);
        count = count + B;
    }
    printf("%f\n",(float)(n-count)/n);
    printf("%d\n",B);

    return 0;
    */

    /*t_word mot0 = createWord("nom");
    t_word mot1 = createWord("verbe");
    printf("%s",mot0.attributes[0]);
*/
    t_model model1 = createRandomModel1();
    printDevModel(model1);
    t_model model2 = createRandomModel2();
    printDevModel(model2);
};