#include <assert.h>

/*
  * "nested2.c" from InvGen benchmark suite
  */
/*@
requires l > 0;
*/
void foo(int l) {
  int i, k, n;

  for (k = 1; k < n; k++) {
    /*@
    loop invariant l <= n;
    loop invariant k <= n;
    loop invariant 1 <= k;
    loop assigns i;
    */
    for (i = l; i < n; i++) {

    }
    /*@
    loop invariant l <= n;
    loop invariant l <= i;
    loop invariant k <= n;
    loop invariant i <= n;
    loop invariant 1 <= k;
    loop assigns i;
    ```c;
    ```;
    Looking at the code structure and the pattern from previous examples, here are the loop invariants for the infill location:;
    */
    for (i = l; i < n; i++) {
      // @ assert 1 <= k;
    }
  }

}