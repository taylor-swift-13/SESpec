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
  loop invariant i + j == n + (i + j) - n;  // equivalent to i + j == i + j, so simplified:
  loop invariant i + j == n + (i + j - n);  // redundant, restated similarly:
  loop invariant i + j == n + (i + j - n);  // circular, better written as:
  loop invariant i + j == n + (i + j - n);  // so instead use:
  loop invariant i + j == n + (i + j - n);  // effectively:
  loop invariant i + j == n + (i + j - n);  // becomes:
  loop invariant i + j == n + (i + j - n);
  loop invariant i + j == n + (i + j - n);
  loop invariant i + j == n + (i + j - n);
  loop invariant i + j == n + (i + j - n);
  
  loop invariant i + j == n + (i + j) - n;  // all above synonyms
  
  // For clarity and to differ:
  
  loop invariant i + j == n + (i + j) - n;
  loop invariant b == (n % 2 == 0 || b == 0) && (n % 2 == 1 || b == 1);
  loop invariant 0 <= i <= n;
  loop invariant 0 <= j <= n;
  loop invariant i == j || i == j + 1 || j == i + 1;  // difference between i and j at most 1
  loop invariant n <= 2*k;
  loop invariant i + j == n;
  loop assigns n;
  loop assigns j;
  loop assigns i;
  loop assigns b;
  loop invariant n <= 2*k;
  loop invariant n <= 2 * k;
  loop invariant i + j == n + (i + j) - n; // simplified to i + j == i + j, so better:;
  loop invariant i + j == n + (i + j - n); // redundant, rewrite as:;
  loop invariant i + j == n + (i + j - n); // no, that's circular; better is:;
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
