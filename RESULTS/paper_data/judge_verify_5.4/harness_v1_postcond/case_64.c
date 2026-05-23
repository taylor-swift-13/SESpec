#include <limits.h>


int unknown();

/*@loop invariant 0 <= a;
      loop invariant i == 1 + 2 * a;
      loop invariant j == 1 + a;
      loop invariant i - j == a;
      loop invariant i % 2 == 1;
      loop invariant j >= 1;
      loop invariant b <= 0;
      loop invariant 2 * b + a * (a - 1) == 0;
      loop invariant 0 <= i;
      loop invariant 0 <= j;
      loop invariant 0 <= a;
      loop invariant b <= 0;
      loop assigns a, b, i, j;*/
void stub_A();

/*@loop invariant j == i / 2 + 1;
    loop invariant j == a + 1;
    loop invariant i == 2 * a + 1;
    loop invariant i % 2 == 1;
    loop invariant 1 <= j;
    loop invariant 1 <= i;
    loop invariant 0 <= a;
    loop assigns j;
    loop assigns i;
    loop assigns b;
    loop assigns a;*/
void stub_B();

/*@loop invariant j == i / 2 + 1;
    loop invariant j == a + 1;
    loop invariant i == 2 * a + 1;
    loop invariant i % 2 == 1;
    loop invariant 1 <= j;
    loop invariant 1 <= i;
    loop invariant 0 <= a;
    loop assigns j;
    loop assigns i;
    loop assigns b;
    loop assigns a;*/
void check_A_implies_B() {
    stub_A();
}

/*@loop invariant 0 <= a;
      loop invariant i == 1 + 2 * a;
      loop invariant j == 1 + a;
      loop invariant i - j == a;
      loop invariant i % 2 == 1;
      loop invariant j >= 1;
      loop invariant b <= 0;
      loop invariant 2 * b + a * (a - 1) == 0;
      loop invariant 0 <= i;
      loop invariant 0 <= j;
      loop invariant 0 <= a;
      loop invariant b <= 0;
      loop assigns a, b, i, j;*/
void check_B_implies_A() {
    stub_B();
}
