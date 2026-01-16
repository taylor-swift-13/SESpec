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
    Looking at the code structure and the pattern from previous examples, here are the loop invariants for the infill location:
    
    ```c
    loop invariant l <= i <= n;
    loop invariant l <= n;
    loop invariant k <= n;
    loop invariant 1 <= k;
    loop assigns i;
    ```
    */
    for (i = l; i < n; i++) {
      // @ assert 1 <= k;
    }
  }

}