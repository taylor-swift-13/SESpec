#include <limits.h>


int unknown();

/*@loop invariant 0 <= a;
          loop invariant 0 <= b;
          loop invariant 0 <= i;
          loop invariant 1 <= j;

          loop invariant i == 2 * a;
          loop invariant j == i + 1;
          loop invariant b == a;

          loop invariant i % 2 == 0;
          loop invariant j % 2 == 1;
          loop invariant a == b;
          loop invariant a <= i;
          loop invariant b <= i;
          loop invariant j > i;

          loop invariant \exists integer k; 0 <= k <= a && i == 2 * k;
          loop invariant \exists integer k; 0 <= k <= a && j == 2 * k + 1;
          loop invariant \exists integer k; 0 <= k <= a && b == k;

          loop assigns a, b, i, j;*/
void stub_A();

/*@loop invariant j == i + 1;
    loop invariant j % 2 == 1;
    loop invariant i % 2 == 0;
    loop invariant b == a;
    loop invariant b == a + j - i - 1;
    loop invariant a == i / 2;
    loop invariant a == b;
    loop invariant 1 <= j;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop invariant 0 <= a;
    loop assigns j;
    loop assigns i;
    loop assigns b;
    loop assigns a;*/
void stub_B();

/*@loop invariant j == i + 1;
    loop invariant j % 2 == 1;
    loop invariant i % 2 == 0;
    loop invariant b == a;
    loop invariant b == a + j - i - 1;
    loop invariant a == i / 2;
    loop invariant a == b;
    loop invariant 1 <= j;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop invariant 0 <= a;
    loop assigns j;
    loop assigns i;
    loop assigns b;
    loop assigns a;*/
void check_A_implies_B() {
    stub_A();
}

/*@loop invariant 0 <= a;
          loop invariant 0 <= b;
          loop invariant 0 <= i;
          loop invariant 1 <= j;

          loop invariant i == 2 * a;
          loop invariant j == i + 1;
          loop invariant b == a;

          loop invariant i % 2 == 0;
          loop invariant j % 2 == 1;
          loop invariant a == b;
          loop invariant a <= i;
          loop invariant b <= i;
          loop invariant j > i;

          loop invariant \exists integer k; 0 <= k <= a && i == 2 * k;
          loop invariant \exists integer k; 0 <= k <= a && j == 2 * k + 1;
          loop invariant \exists integer k; 0 <= k <= a && b == k;

          loop assigns a, b, i, j;*/
void check_B_implies_A() {
    stub_B();
}
