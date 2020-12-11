#include "stack_gen.h"

int main() {
    stack s;
    int top;
    StackNew(&s, sizeof(int));
    for (int i = 0; i < 5; i++)
        StackPush(&s, &i);

    for (int i = 0; i < 5; i++) {
        StackPop(&s, &top);
        printf("%d ", top);
    }
    StackDispose(&s);

    StackNew(&s, sizeof(char));
    char A[] = {'a','b','c','d','e'};
    StackPush(&s, &A[0]); StackPush(&s, &A[1]); 
    StackPush(&s, &A[2]); StackPush(&s, &A[3]); 
    StackPush(&s, &A[4]);

    char ch;
    while (s.loglength) {
        StackPop(&s, &ch);
        printf("%c ", ch);
    }
    StackDispose(&s);

    StackNew(&s, sizeof(double));
    double x, y;
    for (x = 0.1; x < 5; x++)
        StackPush(&s, &x);

    while(s.loglength) {
        StackPop(&s, &y);
        printf("%.2f ", y);
    }
    StackDispose(&s);

    return 0;
}