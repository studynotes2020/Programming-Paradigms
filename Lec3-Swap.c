#include <stdio.h>

void swap(int *ap, int *bp) {
    int tmp = *ap;
    *ap = *bp;
    *bp = tmp;
}

int main() {
    int x = 7;
    int y = 117;
    swap(&x, &y);
    printf("%d, %d", x, y);
}