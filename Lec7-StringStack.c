#include "stack_free.h"

void StringFree(void *elem)
{
    // free((char*)elem); this means free entries of elem
    free(*(char**)elem);  // this means free memory block pointed by entries of elem
}

int main() 
{
    const char *friends[] = {"Al", "Bob", "Carl"};
    stack stringStack;
    StackNew(&stringStack, sizeof(char*), StringFree);

    for (int i = 0; i < 3; i++) {
        char *copy = _strdup(friends[i]);
        StackPush(&stringStack, &copy);
    }

    char *name;
    for (int i = 0; i < 3; i++) {
        StackPop(&stringStack, &name);
        printf("%s ", name);
        free(name);
    }
    StackDispose(&stringStack);

    return 0;
}