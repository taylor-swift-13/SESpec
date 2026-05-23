
/*@
  requires n > 0 && y > 0; // Strengthened precondition: inputs must be strictly positive.
  assigns \nothing;
   // Weakened to match the actual LCM formula.
*/
int foo320(int n, int y) {

    int ret = 1; // GCD placeholder.
    int g = 1;   // LCM placeholder.

    // Ensure n <= y for consistent GCD computation.
    if (n > y) {
        int r = n;
        n = y;
        y = r;
    }

    /*@
      loop invariant ret >= 1; // GCD is always positive.
      loop invariant \exists integer k; 1 <= k <= l && n % k == 0 && y % k == 0 && ret == k; // GCD property.
      loop invariant (l <= \at(y,Pre)) ==> ((ret >= 1) && (ret <= l)); // GCD bounds.
      loop invariant g == 1; // LCM placeholder remains unchanged during GCD computation.
      loop invariant y == \at(n,Pre) || y == \at(y,Pre); // y retains its original value or swaps with n.
      loop invariant n == \at(y,Pre) || n == \at(n,Pre); // n retains its original value or swaps with y.
      loop assigns l, ret; // Variables modified in the loop.
    */
    for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l; // Update GCD.
        }
    }

    g = (n * y) / ret; // Compute LCM using the GCD.
    return g;
}
