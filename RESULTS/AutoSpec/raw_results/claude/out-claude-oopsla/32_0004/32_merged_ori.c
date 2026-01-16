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
  loop invariant n <= 2*k;
  loop invariant n % 2 == 1 ==> i + 1 == j;
  loop invariant n % 2 == 0 ==> i == j;
  loop invariant i >= 0 && j >= 0;
  loop invariant 0 <= n;
  loop invariant (i + j) == (2 * n);
  loop assigns n;
  loop assigns j;
  loop assigns i;
  loop assigns b;
  /*@;
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
