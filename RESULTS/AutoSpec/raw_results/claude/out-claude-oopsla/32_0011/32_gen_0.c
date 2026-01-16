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
  loop invariant 0 <= i;
  loop invariant 0 <= j;
  loop invariant i + j == n;
  loop invariant n <= 2*k;
  loop invariant b == (n % 2 == 1);
  loop invariant 0 <= n <= 2*k;
  loop assigns n;
  loop assigns j;
  loop assigns i;
  loop assigns b;
  loop invariant n <= 2*k;
  loop invariant i + j == i + j + n - n; // trivial, skip;
  loop invariant i + j == i + j + n - n; // to remove;
  loop invariant i + j == i + j + n - n; // redundant;
  loop invariant 0 <= n;
  loop assigns n;
  loop assigns j;
  loop assigns i;
  loop assigns b;
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
