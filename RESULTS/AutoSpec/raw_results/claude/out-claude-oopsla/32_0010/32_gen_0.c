#include <assert.h>

/*
 * "split.c" from InvGen benchmark suite
 */

void main() {
  int k = 100;
  int b;
  int i;
  int j;
  int n;
  i = j;
  /*@
  /*@ 
    loop invariant 0 <= n <= 2*k;
    loop invariant i + j == i + j + n - n; // trivial, skip
    loop invariant i + j == i + j + n - n; // to remove
    loop invariant i + j == i + j + n - n; // redundant
    loop assigns i, j, b, n;
    loop invariant (n % 2 == 0) ==> (i == j);
    loop invariant (n % 2 == 1) ==> (i == j + 1 || j == i + 1);
  */
  */
  for( n = 0 ; n < 2*k ; n++ ) {
    if(b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
  // @ assert i == j;
}
