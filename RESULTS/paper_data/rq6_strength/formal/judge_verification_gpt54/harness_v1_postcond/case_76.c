#include <limits.h>


int unknown();

/*@loop invariant 0 <= c <= 36;
    loop invariant z == 36 * y + c;
    loop invariant z - c == 36 * y;
    loop invariant 0 <= z - 36 * y <= 36;
    loop invariant 36 * y <= z <= 36 * y + 36;
    loop invariant x3 == \at(x3,Pre);
    loop invariant x2 == \at(x2,Pre);
    loop invariant x1 == \at(x1,Pre);
    loop invariant y == \at(y,Pre);
    loop assigns z, c;*/
void stub_A(int y,int x1,int x2,int x3);

/*@loop invariant z == 36 * y + c;
    loop invariant c <= 36;
    loop invariant 0 <= c;
    loop assigns z;
    loop assigns c;*/
void stub_B(int y,int x1,int x2,int x3);

/*@loop invariant z == 36 * y + c;
    loop invariant c <= 36;
    loop invariant 0 <= c;
    loop assigns z;
    loop assigns c;*/
void check_A_implies_B(int y,int x1,int x2,int x3) {
    stub_A(y, x1, x2, x3);
}

/*@loop invariant 0 <= c <= 36;
    loop invariant z == 36 * y + c;
    loop invariant z - c == 36 * y;
    loop invariant 0 <= z - 36 * y <= 36;
    loop invariant 36 * y <= z <= 36 * y + 36;
    loop invariant x3 == \at(x3,Pre);
    loop invariant x2 == \at(x2,Pre);
    loop invariant x1 == \at(x1,Pre);
    loop invariant y == \at(y,Pre);
    loop assigns z, c;*/
void check_B_implies_A(int y,int x1,int x2,int x3) {
    stub_B(y, x1, x2, x3);
}
