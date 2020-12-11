#ifndef STACK_GEN_H
#define STACK_GEN_H

#include <stdio.h>   // NULL
#include <string.h>  // memcpy, _strdup
#include <stdlib.h>  // realloc
#include <assert.h>  // assert

// Generic stack
typedef struct {
    void *elems;
    int elemSize;  // cannot assume int size (4), need info of data size
    int loglength;
    int alloclength;
    void (*freefn)(void *);  // to solve dangling pointers problem
} stack;

void StackNew(stack *s, int elemSize, void (*freefn)(void*));
void StackDispose(stack *s);
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);
static void StackGrow(stack *s);  // static for a function (not method) indicate private function

#include "stack_free.c"

#endif

