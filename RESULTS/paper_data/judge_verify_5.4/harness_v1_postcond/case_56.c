#include <limits.h>


int unknown();

/*@loop invariant count >= 0;
          loop invariant count >= 0;
          loop invariant \true;
          loop assigns term, exp, count;*/
void stub_A(int x);

/*@loop invariant term == 0 || term == term;
    loop assigns term;
    loop assigns exp;
    loop assigns count;*/
void stub_B(int x);

/*@loop invariant term == 0 || term == term;
    loop assigns term;
    loop assigns exp;
    loop assigns count;*/
void check_A_implies_B(int x) {
    stub_A(x);
}

/*@loop invariant count >= 0;
          loop invariant count >= 0;
          loop invariant \true;
          loop assigns term, exp, count;*/
void check_B_implies_A(int x) {
    stub_B(x);
}
