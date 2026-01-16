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
  loop invariant j <= n;
  loop invariant j <= n || i <= n;
  loop invariant j <= n || 0 <= j;
  loop invariant j <= n || 0 <= i;
  loop invariant j < n;
  loop invariant i <= n;
  loop invariant i <= n || 0 <= j;
  loop invariant i < n;
  loop invariant i + j == n;
  loop invariant b == (n % 2 == 0 ? (b == 0 || b == 1) : (b == 0 || b == 1));
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop invariant 0 <= i || i <= n;
  loop invariant 0 <= i || 0 <= j;
  loop invariant 0 < j;
  loop invariant 0 < j;
  loop invariant 0 < j;
  loop invariant 0 < j;
  loop invariant 0 < j;
  loop invariant 0 < j;
  loop invariant 0 < j;
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
