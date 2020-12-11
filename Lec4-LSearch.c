#include <stdio.h>
#include <string.h>
#include <stddef.h>

int int_search(int key, int array[], int size) {
    // if void, not int, lose the info of looping and compare
    for (int i = 0; i < size; i++)
        if (array[i] == key)
            return i;

    return -1;
}

void *lsearch(void *key, void *base, int n, int elemSize) {
    for (int i = 0; i < n; i++) {
        void *elemAddr = (char*)base + i * elemSize;  // bcs no type info, have to calculate the step. Cast to char* bcs void* can't do the arithmetic
        if (memcmp(key, elemAddr, elemSize) == 0) { // compare bit pattern
            return elemAddr;
        }
    }
    return NULL;
}

void *lsearch2(void *key, void *base, int n, int elemSize, int (*cmpfn)(void *, void *)) {
    // replace memcmp with customize compare function
    // next lecture
}

int main() {
    int arr[5] = {10,20,30,40,50};
    printf("%d\n", int_search(30, arr, 5));

    int key = 30;
    int* res = lsearch(&key, arr, 5, sizeof(int));  // return the address of the found key
    printf("%d\n", *res);

    return 0;
}