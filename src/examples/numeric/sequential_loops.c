// Pattern: several sequential while-loops over disjoint ranges, with a
// shared accumulator whose final value is a sum of the loop bounds. The
// invariant of each loop must summarize what was contributed BEFORE the
// loop entered, so the final assertion can chain facts across loops.

#include <limits.h>

/*@
  requires 0 <= n0 && n0 < INT_MAX / 2;
  requires 0 <= n1 && n1 < INT_MAX / 2;
*/
void sequential_count(int n0, int n1) {
    int i0 = 0;
    int k = 0;

    /*@
      loop invariant 0 <= i0 <= n0;
      loop invariant k == i0;
      loop assigns i0, k;
      loop variant n0 - i0;
    */
    while (i0 < n0) {
        i0++;
        k++;
    }
    // After loop 1: k == n0.

    int i1 = 0;
    /*@
      loop invariant 0 <= i1 <= n1;
      loop invariant k == n0 + i1;
      loop assigns i1, k;
      loop variant n1 - i1;
    */
    while (i1 < n1) {
        i1++;
        k++;
    }
    // After loop 2: k == n0 + n1.

    int j = 0;
    /*@
      loop invariant 0 <= j <= n0 + n1;
      loop invariant k == n0 + n1;
      loop assigns j;
      loop variant (n0 + n1) - j;
    */
    while (j < n0 + n1) {
        /*@ assert k > 0 || (n0 == 0 && n1 == 0); */
        j++;
    }
}
