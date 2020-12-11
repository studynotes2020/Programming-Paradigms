/*
    This lecture is about how program stores variable in the memory
    and how C get translated to assembly code who manipulcates memory directly

*/


int foo() {
    int i;
    int j;
    i = 10;
    j = i + 7;
    j++;

}

/*
Assembly code
M is the whole memory
R1 is the base address
4 is the offset
M[R1 + 4] = 10;  // i=10 Store operation

R2 = M[R1 + 4];  // j=i+7 general register load operation
R3 = R2 + 7;  // ALU operation
M[R1] = R3;  // Store operation

R2 = M[R1];  // j++
R2 = R2 + 1;
M[R1] = R2;  // overwrite result back

*/

int foo2() {
    int i;
    short s1;  // s1, s2 laid down below i
    short s2;

    /*
     -----
    |     |  i
     -----
    |  |  |  s1, s2
     -- --
    */

    i = 200; // M[R1 + 4] = 200
    s1 = i;  // R2 = M[R1 + 4]; M[R1 + 2] = .2 R2; only assign two bytes
    s2 = s1 + 1; 
    // R2 = .2 M[R2 + 2]; only assign 2 bytes
    // R3 = R2 + 1;
    // M[R1] = .2 R3;
}

int foo3() {
    int array[4];
    int i;
    for (i = 0; i < 4; i++){
        array[i] = 0;
    }
    i--;
}
/* 
PC => Program counter stores address of the currenly executing instruction

Assembly code below is a for loop
M[R1] = 0;
R2 = M[R1];
BGE R2, 4, PC + 40;  multiple 4, brach on greater equal, others BEQ, BNQ, BGE, BGT, BLE, BLT
R3 = M[R1];  R3 stores value of i
R4 = R3 * 4;  R4 stores the distance of bytes
R5 = R1 + 4;  R5 stores base address of array
R6 = R4 + R5;  R6 has address that get value zero
M[R6] = 0;
// End of loop 1, Execute i++
R2 = M[R1];
R2 = R2 + 1;
M[R1] = R2;
JMP PC - 40   jump back 10 instruction * 4
// then execute i--

*/


struct fraction {
    int num;
    int denum;
};

int foo4() {
    struct fraction pi;
    pi.num = 22;  // M[R1] = 22
    pi.denum = 7; // M[R1 + 4] = 7
    ((struct fraction*)&pi.denum)->denum = 451;  // get the base address of pi.denum, see it as struct fraction, go the denum field, put 451
    // M[R1 + 8] = 451;  when case no additional assembly code generated, it just let compiler see the code differrently so that it can perform certain operation which is asked for
}



