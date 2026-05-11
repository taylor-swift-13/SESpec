// Pattern: nondeterministic-controlled loop where the right invariant is a
// parity / modular-arithmetic relation between the iteration variables.
// Useful when the loop body has unknown() branches and the only state
// preserved across all branches is `(x + y) % 2 == 0` or similar.

int unknown();

/*@
  requires \true;
  ensures \result == 0 || \result == 1;
*/
int parity_walk(int n) {
    int x = 0;
    int y = 0;

    /*@
      loop invariant (x + y) % 2 == 0;
      loop invariant 0 <= x;
      loop invariant 0 <= y;
      loop assigns x, y;
    */
    while (unknown()) {
        if (unknown()) {
            x = x + 1;
            y = y + 1;
        } else {
            x = x + 2;
        }
    }
    // After the loop the parity invariant survives regardless of which
    // branch fired; hence (x + y) % 2 == 0 holds and the post is provable.
    return (x + y) % 2;
}
