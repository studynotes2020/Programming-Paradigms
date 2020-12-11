// #include <stdlib.h>  // header file include prototype only, didn't tell the compiler the implementation
// #include <stdio.h>  // gcc still print though didn't see prototype
// #assert <assert.h>  // only macro allowed to use 
// #include <assert.h>
int strlen(char *s, int len); // if want to suppress warnings, put a prototype here


// Part 1 to talk about header files
int main() {
    void *mem = malloc(400);
    assert (mem != NULL);
    printf("Yay!\n");
    free(mem);
    return 0;

}

int LecPart2() {
    int num = 65;
    // in little endian, this print one, bcs it points to "65 0 0 0" and 65 is 'a'
    // in big endian, this print zero
    int length = strlen((char*)&num, num);
    printf("Length = %d\n", length);
    return 0;
}

// Part 3
// Real prototype -> int memcpy(void *v1, void *v2, int n)
int memcmp(void *v1);
int memcmp(void *v1) 
{
    int n = 17;
    int m = memcmp(&n); // take two memory block before it as v2, n and execute with those three values
}

/*
Segmentation fault - Always comes when dereference a bad pointer. Can't dereference a NULL pointer, *(NULL), can't jump to 0000 address. It is not part of any address segment

Bus error
void *vp = xxxx;  xxxx is not some valid address of any segment (data, stack, heap, code)
*(short*) vp = 7;  throw bus error, if odd address for short*

Compiler always assume address starts with multiple of four
*(int*) vp = 55; vp wasn't multiple of 4, so bus error

Bus error easily happen when manually pack data
*/

int LecPart3() {
    int i;
    int array[4];
    for (i = 0; i <= 4; i++) {
        array[i] = 0;  // buffer overflow at i = 4
    }
    return 0;
}

int LecPart4() {
    int i;
    short array[4];
    for (i = 0; i <= 4; i++) {
        array[i] = 0;  // buffer overflow at i = 4
    }
    // No problem for big endian (20% overhead), bcs overwritten value is 0, but infinite loop for little endian system bcs 4 get overwritten
    return 0;
}

void LecPart5() {
    int array[4]; // array is above i this time
    int i;
    for(i = 0; i <= 4; i++) {
        array[i] -= i;  // buffer overflow but this time overwritten instruction
    }
}



