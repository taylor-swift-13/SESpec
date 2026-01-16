#include <assert.h>

/*
 * "nested4.c" from InvGen benchmark suite
 */

/*@
requires l > 0;
requires n > l;
*/
void foo(int n, int l) {
  int i,k;


  for (k=1; k<n; k++){
    /*@
    loop invariant k <= n;
    loop invariant 1 <= k;
    loop assigns i;
    */
    for (i=l; i<n; i++) {
    }
    /*@
    loop invariant l <= i <= n;
    loop invariant k <= n;
    loop invariant 1 <= k;
    loop invariant \forall integer m; l <= m < i ==> 1 <= m;
    loop assigns i;
    */
    for (i=l; i<n; i++) {
      // @ assert 1<=i;
    }
  }

}
