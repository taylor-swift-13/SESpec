#include <assert.h>

int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * ex49 from NECLA Static Analysis Benchmarks
 */
/*@
requires n >= 0;
*/
void foo(int n) {
  int i, sum = 0;

  /*@
  loop invariant sum == i * (i - 1) / 2;
  loop invariant i <= n;
  loop invariant 0 <= sum;
  loop invariant 0 <= i;
  loop assigns sum;
  loop assigns i;
  ```c;
  ```;
  The loop:;
  Looking at this problem, I need to generate loop invariants for the loop that sums integers from 0 to n-1.;
  Here are the loop invariants:;
  - Needs to prove `sum >= 0` after the loop;
  - Iterates with `i` from 0 to n-1;
  - Accumulates `sum = sum + i`;
  */
  for (i = 0; i < n; ++i)
    sum = sum + i;

  // @ assert sum >= 0;
}