/*
    Continue discussion on how C code laid down in memory
*/

void foo(int bar, int *baz)
{
    char snink[4];
    short *why;

    /*
        _________  
        _________  bar   
        _________  baz
        _________  return link, get to this when function exits
        |_|_|_|_|  snink[4]
        _________  why

        first augment always laid down last
        variables declared first, get to the top of the stack
    */

   why = (short*)(snink + 2);
   *why = 50;
}

int main(int argc, char **argv)
{
    int i = 4;
    foo(i, &i);
    return 0;

    /*
        ______
        ______ argv points to another array
        ___2__ argc
        ______ saved PC

        SP = SP - 4;
        M[SP] = 4;
        SP = SP - 8;
        R1 = M[SP + 8];
        R2 = SP + 8;
        M[SP] = R1;
        M[SP + 4] = R2;
        CALL <foo>
        SP = SP + 8;  // inside foo
        R1 = SP + 6;
        M[SP] = R1;
        R1 = M[SP];
        M[R1] = .2 50;
        SP = SP + 8;
        RET;  // jump back to foo call
    */
}

int factorial(int n)
{
    if (n == 1) return 1;
    return n * factorial(n - 1);
    /*
        R1 = M[SP + 4];  // have to laid down some num, hence 4
        BNE R1, 0, PC + 12
        RV = 1;  // like a locker, that get value when recursive function return
        RET;
        R1 = M[SP + 4];
        R1 = R1 - 1;
        SP = SP - 4;
        M[SP] = R1;
        CALL <factorial>
        SP = SP + 4;
        R1 = M[SP + 4];
        RV = RV * R1;
        RET;

    */

}