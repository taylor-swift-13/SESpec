#include <assert.h>

/*
  * "nested2.c" from InvGen benchmark suite
  */
/*@
requires l > 0;
*/
void foo(int l) {
  int i, k, n;

  /*@
  loop invariant l <= n;
  loop invariant 1 <= n;
  loop assigns n;
  loop assigns k;
  loop assigns i;
  */
  for (k = 1; k < n; k++) {
    /*@
    loop invariant l <= n;
    loop invariant k <= n;
    loop invariant 1 <= k;
    loop invariant 0 < l;
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
    loop invariant 0 < l;
    loop assigns i;
    */
    for (i = l; i < n; i++) {
      // @ assert 1 <= k;
    }
  }

}