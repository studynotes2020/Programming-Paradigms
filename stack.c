#include "stack.h"

void StackNew(stack *s)
{
    s->loglength = 0;  // logical length
    s->alloclength = 4;
    s->elems = malloc(4 * sizeof(int)); // one argument of how many bytes needed
    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
    free(s->elems);  // delete in c++
    // s not dynamically allocated, so no need to free s
}

void StackPush(stack *s, int value)
{
    if (s->loglength == s->alloclength) {
        s->alloclength *= 2;
        // no equivalent of realloc in c++
        // realloc return address pointing to the second argument
        // if memory block of the original block unused, just extend it. If used, call malloc at other memory location
        // if first argument is null, realloc is malloc
        s->elems = realloc(s->elems, s->alloclength*sizeof(int));
        assert(s->elems != NULL); // if realloc fails, return NULL
    }

    s->elems[s->loglength] = value;
    s->loglength++;
}

int StackPop(stack *s)
{
    assert(s->loglength > 0);
    s->loglength--;
    return s->elems[s->loglength];
    // for faster operation, stack doesn't shrink array
}
























