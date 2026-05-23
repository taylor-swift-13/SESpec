#include <limits.h>


int unknown(void);
int unknown();

/*@loop invariant count >= 0;
      loop invariant count % 2 == 0 || count % 2 == 1;
      loop invariant multFactor == 0 || multFactor == 1 || multFactor == -1;
      loop invariant term == term;
      loop invariant evenExp == evenExp;
      loop invariant oddExp == oddExp;
      loop invariant (count / 2) % 2 == 0 || (count / 2) % 2 == 1;
      loop invariant evenExp >= 0.0 || evenExp <= 0.0;
      loop invariant oddExp >= 0.0 || oddExp <= 0.0;
      loop assigns term, multFactor, evenExp, count, oddExp;*/
void stub_A(int octant, int x);

/*@loop invariant term >= 0 || term <= 0;
    loop invariant term == x || term == 0 || term >= 0 || term <= 0;
    loop invariant oddExp == x || oddExp >= x || oddExp <= x;
    loop invariant octant == 1;
    loop invariant multFactor == 1 || multFactor == -1 || multFactor == 0;
    loop invariant multFactor == 0 || multFactor == 1 || multFactor == -1;
    loop invariant multFactor == -1 || multFactor == 1 || multFactor == 0;
    loop invariant evenExp == oddExp || evenExp != oddExp;
    loop invariant evenExp == 1.0 || evenExp >= 1.0 || evenExp <= 1.0;
    loop assigns term;
    loop assigns oddExp;
    loop assigns multFactor;
    loop assigns evenExp;
    loop assigns count;*/
void stub_B(int octant, int x);

/*@loop invariant term >= 0 || term <= 0;
    loop invariant term == x || term == 0 || term >= 0 || term <= 0;
    loop invariant oddExp == x || oddExp >= x || oddExp <= x;
    loop invariant octant == 1;
    loop invariant multFactor == 1 || multFactor == -1 || multFactor == 0;
    loop invariant multFactor == 0 || multFactor == 1 || multFactor == -1;
    loop invariant multFactor == -1 || multFactor == 1 || multFactor == 0;
    loop invariant evenExp == oddExp || evenExp != oddExp;
    loop invariant evenExp == 1.0 || evenExp >= 1.0 || evenExp <= 1.0;
    loop assigns term;
    loop assigns oddExp;
    loop assigns multFactor;
    loop assigns evenExp;
    loop assigns count;*/
void check_A_implies_B(int octant, int x) {
    stub_A(octant, x);
}

/*@loop invariant count >= 0;
      loop invariant count % 2 == 0 || count % 2 == 1;
      loop invariant multFactor == 0 || multFactor == 1 || multFactor == -1;
      loop invariant term == term;
      loop invariant evenExp == evenExp;
      loop invariant oddExp == oddExp;
      loop invariant (count / 2) % 2 == 0 || (count / 2) % 2 == 1;
      loop invariant evenExp >= 0.0 || evenExp <= 0.0;
      loop invariant oddExp >= 0.0 || oddExp <= 0.0;
      loop assigns term, multFactor, evenExp, count, oddExp;*/
void check_B_implies_A(int octant, int x) {
    stub_B(octant, x);
}
