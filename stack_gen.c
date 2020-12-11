#include "stack_gen.h"

void StackNew(stack *s, int elemSize)
{
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->loglength = 0;  // logical length
    s->alloclength = 4;
    s->elems = malloc(4*elemSize);
    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
    free(s->elems);
}

void StackPush(stack *s, void *elemAddr)
{
    if (s->loglength == s->alloclength) StackGrow(s);
    // can't do pointer arithmetic on void* so cast to char*
    void *target = (char*)s->elems + s->loglength * s->elemSize;  // calculate the address to add value
    memcpy(target, elemAddr, s->elemSize); // (destination, soure, length)
    s->loglength++;
}

static void StackGrow(stack *s)
{
    s->alloclength *= 2;
    s->elems = realloc(s->elems, s->alloclength*s->elemSize);
}

void StackPop(stack *s, void *elemAddr)
{
    void *source = (char*)s->elems + (s->loglength-1) * (s->elemSize);
    memcpy(elemAddr, source, s->elemSize);
    s->loglength--;
}

