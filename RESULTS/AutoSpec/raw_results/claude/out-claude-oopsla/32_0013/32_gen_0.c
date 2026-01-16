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
  loop invariant 0 <= n <= 2*k;
  loop invariant i + j == i + j + n; 
  loop invariant (n % 2 == 0) ==> i == j + n/2;
  loop invariant (n % 2 == 1) ==> i == j + (n+1)/2 || j == i + (n+1)/2;
  loop invariant b == (n % 2 == 0);
  loop assigns i;
  loop assigns j;
  loop assigns n;
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
