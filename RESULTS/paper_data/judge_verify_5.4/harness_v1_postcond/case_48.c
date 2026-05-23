#include <limits.h>


int unknown();

/*@loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop assigns x, y, xa, ya;*/
void stub_A();

/*@loop invariant \true;
    loop assigns ya;
    loop assigns y;
    loop assigns xa;
    loop assigns x;*/
void stub_B();

/*@loop invariant \true;
    loop assigns ya;
    loop assigns y;
    loop assigns xa;
    loop assigns x;*/
void check_A_implies_B() {
    stub_A();
}

/*@loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop assigns x, y, xa, ya;*/
void check_B_implies_A() {
    stub_B();
}
