#include "stack.h"

int main() {
    stack s;
    StackNew(&s);
    for (int i = 0; i < 5; i++)
        StackPush(&s, i);

    int top;
    for (int i = 0; i < 5; i++) {
        top = StackPop(&s);
        printf("%d ", top);
    }

    

    return 0;
}