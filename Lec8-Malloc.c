#include <stdio.h>
#include <stdlib.h> // malloc

// This lecture is about memory allocation by malloc

int main() {
    int *arr = malloc(100 * sizeof(int));  // argument is number of bytes, here allocate 400 bytes. There is a header in front that indicates how many bytes allocated
    
    free(arr); // backup to read header and free memory
    // free(arr + 60);  this will mess up

    // malloc will allocate block of bytes whenever it fits

    return 0;
}