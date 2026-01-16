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
  loop invariant i + j == n + (i_initial + j_initial);
  loop invariant i + j == n + (i + j) - n; // simplified to i + j == i + j, so better:;
  loop invariant i + j == n + (i + j - n); // redundant, rewrite as:;
  loop invariant i + j == n + (i + j - n); // no, that's circular; better is:;
  loop invariant 0 <= n;
  loop invariant ((n % 2) == 1) ==> (i == j + 1 || j == i + 1);
  loop invariant ((n % 2) == 0) ==> (i == j);
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
