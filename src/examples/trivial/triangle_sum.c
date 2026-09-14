// Pattern: a loop accumulates the running sum of integers (triangular
// numbers). The CLOSED-FORM polynomial invariant equates `2*s` to a
// quadratic in the counter `i`:
//
//     2 * s == i * (i + 1)
//
// Derivation: at iteration k, i = k and s = 1 + 2 + ... + k = k*(k+1)/2,
// so 2s = i*(i+1). The equality is preserved by direct substitution
// each iteration: when `i` becomes `i+1` and `s` becomes `s + i+1`,
// 2*(s + i+1) = 2s + 2(i+1) = i*(i+1) + 2(i+1) = (i+1)*(i+2). ✓
//
// Same closed-form approach applies whenever the loop body increments
// a counter and adds a linear function of the counter into an
// accumulator. No disjunctions, no implications. The post-loop assert
// is discharged by instantiating the polynomial at the exit value of
// the counter (set by the loop exit condition).

void triangle_sum_demo(int n) {
    int i = 0;
    int s = 0;

    /*@
      requires n >= 0;
      loop invariant 0 <= i <= n;
      loop invariant 2 * s == i * (i + 1);
      loop assigns i, s;
    */
    while (i < n) {
        i = i + 1;
        s = s + i;
    }
    /*@ assert 2 * s == n * (n + 1); */
}
