#include <limits.h>


int unknown();

/*@loop invariant octant1 == 0;
          loop invariant term == term;
          loop invariant evenExp == evenExp;
          loop invariant oddExp == oddExp;
          loop assigns term, multFactor, evenExp, count, oddExp;*/
void stub_A(int octant1, int octant2, int x);

/*@loop invariant term >= 0 || term < 0;
    loop invariant oddExp >= 0.0 || oddExp <= 0.0;
    loop invariant multFactor == 1 || multFactor == -1 || multFactor == 0;
    loop invariant evenExp >= 0.0 || evenExp <= 0.0;
    loop invariant evenExp == oddExp || evenExp != oddExp;
    loop assigns term;
    loop assigns oddExp;
    loop assigns multFactor;
    loop assigns evenExp;
    loop assigns count;*/
void stub_B(int octant1, int octant2, int x);

/*@loop invariant term >= 0 || term < 0;
    loop invariant oddExp >= 0.0 || oddExp <= 0.0;
    loop invariant multFactor == 1 || multFactor == -1 || multFactor == 0;
    loop invariant evenExp >= 0.0 || evenExp <= 0.0;
    loop invariant evenExp == oddExp || evenExp != oddExp;
    loop assigns term;
    loop assigns oddExp;
    loop assigns multFactor;
    loop assigns evenExp;
    loop assigns count;*/
void check_A_implies_B(int octant1, int octant2, int x) {
    stub_A(octant1, octant2, x);
}

/*@loop invariant octant1 == 0;
          loop invariant term == term;
          loop invariant evenExp == evenExp;
          loop invariant oddExp == oddExp;
          loop assigns term, multFactor, evenExp, count, oddExp;*/
void check_B_implies_A(int octant1, int octant2, int x) {
    stub_B(octant1, octant2, x);
}
