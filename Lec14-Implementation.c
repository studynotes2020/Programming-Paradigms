int printf(const char *control, ...);  // to suport ..., the compiler place arguments as stack

void foo()
{
    int array[4];
    int i;
    for (i = 0; i <= 4; i++)
        array[i] -= 4; // buffer overflow that overwritten the instruction and will cause infinity loop
}

int main()
{
    DeclareAndInitArray();  // when this return, it doesn't clear out memory
    PrintArray();  // so this still can print out the footprint
    printf("\nHello\n");
    printf("%d + %d = %d\n", 4, 4, 8);
}

void DeclareAndInitArray()
{
    int array[100];
    int i;
    for (i = 0; i < 100; i++)
        array[i] = i;
}

void PrintArray()
{
    int array[100];
    int i;
    for (i = 0; i < 100; i++)
        printf("%d\t", array[i]);
}

struct base {
    int code;  // when initialize, always type_one or type_two value in the memory
};

struct type_one {
    int code;
    // other parameters
};

struct type_two {
    int code;
    // other parameters
};

/*
    Three segments in the memory
    stack, heap, codes(instructions)

    gcc, make, FF, clock all got their own stack, heap, codes segment.

    All seems run concurrently
*/

// Concurrent Programming for next
// Can have each thread run throught finish then start next thread
// Or each thread run a little each time segment
int concurrent()
{
    int numAgents = 10;
    for (int i = 0; i < 10; i++)
        sellTickets(i, 15);
}
