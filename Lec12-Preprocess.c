#include <stdio.h>

// C Preprocessing, compilation, linking

#define kWidth 40
#define kHeight 80
#define kPerimeter 2*(kWidth + kHeight)  // get replaced by 40 and 80

// macros
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define NthElemAddr(base, elemSize, index) ((char*)base + index * elemSize)
#define assert(cond) (cond) ? ((void) 0) : fprintf(stderr, "..."), exit(0)  // if true dont do anything, else print out line number and exit


int main() {
    // MAX(10, 40) will replace by (((10) > (40)) ? (10) : (40)) in preprocessing
    printf("%d\n", MAX(10, 40));

    MAX(40.2, "Hello"); // this will cause problem in compilation but no error in preprocess which is just text replacement


    return 0;
}

void *vectorNth(vector *v, int position) {
    assert(position >= 0);  // assert is also macro
    assert(position < v->loglength);
    return NthElemAddr(v->elem, v->elemSize, position);
}

#ifdef NDEBUG
    #define assert(cond) (void) 0
#else
    #define assert(cond) (cond) ? ((void) 0) : fprintf(stderr, "..."), exit(0)
#endif

int max = (fib(100) > fact(4000)) ? fib(100) : fact(4000);
=
int larger = MAX(m++, n++);
int larger = ((m++) > (n++)) ? (m++) : (n++);
// Back in the days, memory 64k to program, easily manageable, so allow programmers much freedom 


#include <stdio.h>  // system header, shipped with compiler
#include <assert.h>
#include "vector.h" // user defined header file, look inside current folder

// gcc -E vector.c  preprocessed but don't compile
#ifndef _vector_h_
#define _vector_h_


#endif

