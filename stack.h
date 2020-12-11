#ifndef STACK_H
#define STACK_H

#include <stdio.h>   // NULL
#include <string.h>  // memcpy
#include <stdlib.h>  // realloc
#include <assert.h>  // assert

// C can't make data private. Programmers have to be self-dicipline
typedef struct {
    int *elems;
    int loglength;
    int alloclength;
} stack;

void StackNew(stack *s);
void StackDispose(stack *s);
void StackPush(stack *s, int value);
int StackPop(stack *s);

#include "stack.c"

#endif
