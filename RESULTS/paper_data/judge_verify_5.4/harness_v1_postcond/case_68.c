#include <limits.h>


/*@
  predicate even(unsigned int x) = (x % 2) == 0;
  predicate odd(unsigned int x) = (x % 2) == 1;
*/

/*@loop invariant (0 < \at(n,Pre)) ==> (l <= n);
      loop invariant (0 < \at(n,Pre)) ==> (j == l / 2);
      loop invariant (0 < \at(n,Pre)) ==> (i == (l + 1) / 2);
      loop invariant (0 < \at(n,Pre)) ==> ((l % 2) == 0 ==> i == j);
      loop invariant (0 < \at(n,Pre)) ==> ((l % 2) == 1 ==> i == j + 1);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, j, l;*/
void stub_A(unsigned int n);

/*@loop invariant l <= n;
    loop invariant j == l / 2;
    loop invariant i == (l + 1) / 2;
    loop invariant i + j == l;
    loop invariant 0 <= l;
    loop assigns l;
    loop assigns j;
    loop assigns i;*/
void stub_B(unsigned int n);

/*@loop invariant l <= n;
    loop invariant j == l / 2;
    loop invariant i == (l + 1) / 2;
    loop invariant i + j == l;
    loop invariant 0 <= l;
    loop assigns l;
    loop assigns j;
    loop assigns i;*/
void check_A_implies_B(unsigned int n) {
    stub_A(n);
}

/*@loop invariant (0 < \at(n,Pre)) ==> (l <= n);
      loop invariant (0 < \at(n,Pre)) ==> (j == l / 2);
      loop invariant (0 < \at(n,Pre)) ==> (i == (l + 1) / 2);
      loop invariant (0 < \at(n,Pre)) ==> ((l % 2) == 0 ==> i == j);
      loop invariant (0 < \at(n,Pre)) ==> ((l % 2) == 1 ==> i == j + 1);
      loop invariant (!(0 < \at(n,Pre))) ==> ((l == 0)&&(i == 0)&&(j == 0)&&(n == \at(n,Pre)));
      loop invariant n == \at(n,Pre);
      loop assigns i, j, l;*/
void check_B_implies_A(unsigned int n) {
    stub_B(n);
}
