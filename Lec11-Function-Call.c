#define kWidth 480  // global variable
#define kHeight 720

printf("Width is %d\n", kWidth);  // replace kWidth with 480 in preprocessing. Pure token search and replace.
int area = kWidth * kHeight;





void swap(int *ap, int *bp) {
    int tmp = *ap;
    *ap = *bp;
    *bp = tmp;
}

void foo()
{
    int x;
    int y;

    x = 11;
    y = 17;
    swap(&x, &y);
}
/*
SP = SP - 8;
M[SP + 4] = 11;
M[SP] = 17;
R1 = SP;   &y
R2 = SP + 4;  &x
SP = SP - 8;
M[SP] = R2;
M[SP + 4] = R1;
CALL <SWAP>  
SP = SP + 8;  balance SP-8
SP = SP +8;  balance SP-8
RET;


<SWAP>: associated with SP=SP-4
= Below three blocks correspond to three lines in swap
R1 = M[SP + 8];
R2 = M[R1];
M[SP] = R2;
=
R1 = M[SP + 12];  load value of bp
R2 = M[R1];
R3 = M[SP + 8];
M[R3] = R2;
=
R1 = M[SP];
R2 = M[SP + 12];
M[R2] = R1;
=
SP = SP + 4; bring the stack back to saved PC
*/




// suppose we have & from C++
// & is just automatic dereference pointer
void swap2(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

{
    int x = 17;
    int y = x;  // y has its own copy with value 17
    int& z = y;  // this means z points to y
    int* z = &y;  // this and above line converts into same assembly code. For int& z declaration, one cannot change z to associate to other variable. For int* z, one can change z points to other location

    // struct and class is the same when laid down in memory
    // the only difference struct and class is the default access modifier for classes is private, while the default access modifier for struct is public

    // basically there is a switch to see struct or class to switch between private and public
}

class binky {
    public:
        int dunky(int x, int y);
        char *minky(int *z); {  //inline implementation
            int w = *z;
            return slinky + dunky(winky, winky); // actually this pointer passed in as first argument
        }

    private:
        int winky;
        char *blinky;
        char slinky[8];
};

{
    int n = 17;
    binky b;
    b.minky(&n);  // binky::minky(&b, &n) is called in assembly level

}

// C++
class fraction {
    public:
        fraction(int n, int d=1);
        void reduce();
    private:
        // static means can invoke without initialize as an instance. The program can directly use it
        // static methods can't be inherited
        static int gcd(int x, int y);

}

