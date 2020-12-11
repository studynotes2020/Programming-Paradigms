#include <stdio.h>
#include <string.h>

typedef struct {
    int num;
    int denum;
    // memory block: denum stack on top of num
} fractions;

void array1() {
    // Part 2
    int array[10];  
    // array is &array[0]
    // array + k is &array[k]
    // *array is array[0]
    // *(array + k) is array[k]

    array[0] = 44; array[9] = 10; array[5] = 45; 
    array[10] = 1; // in C no bound checking, write the value there
    array[25] = 25;  // still place 25
    array[-4] = 77;  // place 77 at memory -16 bytes from 0
}

void array2() {
    int arr[5];
    arr[3] = 128;
    ((short*)arr)[6] = 2;
    printf("%d", arr[3]);
    ((short*)(((char*)(&arr[1])) + 8))[3] = 100;
}

typedef struct {
    char *name;
    char suid[8];
    int numUnits;
    // memory block => char* at bottom, char array middle, int on top
} Student;


int main() {
    double d = 3.1416;
    char ch = *(char*)&d; // (char*) make it see as storing single character, * get whatever one byte pattern store there
    printf("%c\n", ch);

    short s = 45;
    double d2 = *(double*)&s;  // go to address of s, see it as storing a double, * to get the bit pattern
    printf("%f\n", d2);

    fractions pi;
    pi.num = 22;
    pi.denum = 7;
    printf("%d, %d\n", pi.num, pi.denum);

    ((fractions*)&(pi.denum))->num = 12;  // go to denum address, see is as fraction struct, but 12 on num field
    printf("%d\n", pi.denum);

    ((fractions*)&(pi.denum))->denum = 33;
    printf("%d\n", ((fractions*)&(pi.denum))->denum); // no legal way to access, except to write it again

    // ((fractions*)&(pi.denum))[0].denum;
    // equivalent to (&pi)[1].num

    array1();
    array2();

    Student pupils[4];
    pupils[0].numUnits = 21;
    pupils[2].name = _strdup("Adam"); // duplicate the string in heap
    pupils[3].name = pupils[0].suid + 6; // pupils[0].suid evaluate to a pointer and then go to index 6. pupils[3].name field point to that address
    strcpy(pupils[1].suid, "4041xx"); // copy 40415xx to that field
    strcpy(pupils[3].name, "123456"); // will overwrite the data on name field of pupils[1]
    pupils[7].suid[11] = 'A';

    return 0;
}

