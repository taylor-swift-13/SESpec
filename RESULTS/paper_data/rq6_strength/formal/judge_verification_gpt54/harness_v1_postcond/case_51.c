#include <limits.h>


int unknown();

/*@loop invariant x <= w;
          loop invariant 0 <= w;
          loop invariant y % 2 == 0;
          loop invariant z == 10 * w;
          loop invariant x >= 0;
          loop invariant z >= 0;
          loop invariant x <= w;
          loop invariant w >= x;
          loop invariant z == 10 * w;
          loop invariant y % 2 == 0;
          loop assigns x, y, w, z;*/
void stub_A();

/*@loop invariant z == 10*w;
    loop invariant z == 10 * w;
    loop invariant y >= 0 || y <= 0;
    loop invariant x <= w;
    loop invariant x <= w + 1;
    loop invariant 0 <= z;
    loop invariant 0 <= x;
    loop invariant 0 <= w;
    loop assigns z;
    loop assigns y;
    loop assigns x;
    loop assigns w;*/
void stub_B();

/*@loop invariant z == 10*w;
    loop invariant z == 10 * w;
    loop invariant y >= 0 || y <= 0;
    loop invariant x <= w;
    loop invariant x <= w + 1;
    loop invariant 0 <= z;
    loop invariant 0 <= x;
    loop invariant 0 <= w;
    loop assigns z;
    loop assigns y;
    loop assigns x;
    loop assigns w;*/
void check_A_implies_B() {
    stub_A();
}

/*@loop invariant x <= w;
          loop invariant 0 <= w;
          loop invariant y % 2 == 0;
          loop invariant z == 10 * w;
          loop invariant x >= 0;
          loop invariant z >= 0;
          loop invariant x <= w;
          loop invariant w >= x;
          loop invariant z == 10 * w;
          loop invariant y % 2 == 0;
          loop assigns x, y, w, z;*/
void check_B_implies_A() {
    stub_B();
}
