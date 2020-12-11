#include <stdio.h> // printf
#include <stdlib.h> // malloc, free
#include <assert.h>

int main(int argc, char *argv[])
{
    void *memory = malloc(400);
    assert(memory != NULL);
    printf("Yay!\n");
    free(memory);
    return 0;
}

/*
Compilation

...
CALL <malloc>
...
CALL <fprintf>
...
CALL <printf>
...
CALL <free>
RV = 0;
RET;

There is no assert because got replaced by fprintf
*/