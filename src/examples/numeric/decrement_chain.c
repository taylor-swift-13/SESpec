// Pattern: a counter is BUILT UP across one or more earlier loops, then a
// later loop CONSUMES it by decrementing. The assertion inside the
// consumer loop typically claims the counter is still positive — that
// holds iff the loop invariant `consumed + remaining == total`.
//
// The invariant of each producer loop must persist its contribution into
// the shared counter; the consumer loop's invariant must relate the
// running counter to the iteration variable so the assertion `k > 0`
// follows from the loop condition.

#include <limits.h>

/*@
  requires 0 <= n && n < INT_MAX;
*/
void produce_then_consume(int n) {
    int k = 0;
    int i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant k == i;        // every iteration adds 1 to k
      loop assigns i, k;
      loop variant n - i;
    */
    while (i < n) {
        i++;
        k++;
    }
    // Producer finished: k == n.

    int j = 0;
    /*@
      loop invariant 0 <= j <= n;
      loop invariant k + j == n;    // the relation that lets `assert k > 0` go through
      loop assigns j, k;
      loop variant n - j;
    */
    while (j < n) {
        /*@ assert k > 0 || j == n; */
        j++;
        k--;
    }
    // After consumer: k == 0, j == n.
}
