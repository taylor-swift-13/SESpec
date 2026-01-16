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
  loop invariant n <= 2*k && n >= 0;
  loop invariant n <= 2 * k;
  loop invariant n <= 2 * k || 0 <= j;
  loop invariant n <= 2 * k || 0 <= i;
  loop invariant n < 2 * k;
  loop invariant i + j == n;
  loop invariant b == (n % 2 == 0);
  loop invariant 0 <= j;
  loop invariant 0 <= j || 0 <= i;
  loop invariant 0 <= i;
  loop invariant 0 < j;
  loop invariant 0 < i;
  loop invariant 0 < i;
  loop invariant 0 < i;
  loop invariant 0 < i;
  loop invariant 0 < i;
  loop invariant 0 < i;
  loop invariant 0 < i;
  loop invariant n <= 2*k;
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
