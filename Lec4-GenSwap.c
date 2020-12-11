#include <stdio.h>
#include <string.h>

// void* means no type information
// so need to supply size to know how many bytes to swap
void generic_swap(void *vp1, void *vp2, int size) {
    // void temp = *vpi; can't declare void for temp
    char buffer[size];
    memcpy(buffer, vp1, size);  // copy vp1 of size bytes into buffer
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);

}

int main() {
    int x = 17, y = 37;
    generic_swap(&x, &y, sizeof(int));
    printf("%d, %d\n", x, y);

    double d = 3.141, e = 2.718;
    generic_swap(&d, &e, sizeof(double));
    printf("%f, %f\n", d, e);

    int i = 44;
    short s = 5;
    generic_swap(&i, &s, sizeof(short));  // little endian system shows no problem
    printf("%d, %d\n", i, s);

    char *husband = _strdup("Fred");
    char *wife = _strdup("WilmaWilma");
    generic_swap(&husband, &wife, sizeof(char*)); // swap char* point to the string. if no &, swap the char of the string
    
    i = 0;
    while (husband[i] != '\0') {
        printf("%c", husband[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while (wife[i] != '\0') {
        printf("%c", wife[i]);
        i++;
    }
    

    return 0;
}





