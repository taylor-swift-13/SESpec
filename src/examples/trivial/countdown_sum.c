// Pattern: COUNTDOWN accumulator — the loop body has shape
//     s = s + k;
//     k = k - 1;
// — `s` accumulates the running sum as `k` decreases from its initial
// value down to zero. The CLOSED-FORM polynomial invariant equates
// `2*s` to a quadratic in the loop bound `n` and the current `k`:
//
//     2 * s == (n - k) * (n + k + 1)
//
// Derivation: at iteration t, k = n - t and s = n + (n-1) + ... + (n-t+1)
//     = t*n - (0+1+...+(t-1)) = t*n - t*(t-1)/2.
// Substituting t = n - k: 2s = 2*(n-k)*n - (n-k)*(n-k-1)
//     = (n-k)*(2n - (n-k-1)) = (n-k)*(n + k + 1). ✓
//
// No disjunctions, no implications. The polynomial uses only the
// loop-bound parameter `n` (unchanged by the loop body, so no
// `\at(...)` needed) and the live counter `k`. Same approach applies
// whenever a loop drives a counter monotonically toward a boundary
// while accumulating a linear function of the counter.

void poly_countdown_demo(int n) {
    int s = 0;
    int k = n;

    /*@
      requires n >= 0;
      loop invariant 0 <= k <= n;
      loop invariant 2 * s == (n - k) * (n + k + 1);
      loop assigns k, s;
    */
    while (k > 0) {
        s = s + k;
        k = k - 1;
    }
}
