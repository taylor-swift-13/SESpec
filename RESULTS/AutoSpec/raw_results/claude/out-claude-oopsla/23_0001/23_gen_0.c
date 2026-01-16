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
  Looking at this problem, I need to generate loop invariants for the loop that sums integers from 0 to n-1.
  
  The loop:
  - Iterates with `i` from 0 to n-1
  - Accumulates `sum = sum + i`
  - Needs to prove `sum >= 0` after the loop
  
  Here are the loop invariants:
  
  ```c
  loop invariant 0 <= i <= n;
  loop invariant sum >= 0;
  loop invariant sum == i * (i - 1) / 2;
  loop assigns i;
  loop assigns sum;
  ```
  */
  for (i = 0; i < n; ++i)
    sum = sum + i;

  // @ assert sum >= 0;
}