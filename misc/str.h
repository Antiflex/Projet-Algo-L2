//
// Created by a on 11/11/2022.
//

#ifndef PROJET_ALGO_L2_STR_H
#define PROJET_ALGO_L2_STR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char* str;

//prototypes

str createStrChar(char c);
void addStrSize(str dest, str addend);
void addStrChar(str dest, char addend);

#endif //PROJET_ALGO_L2_STR_H
