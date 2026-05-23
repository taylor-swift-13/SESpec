
void foo47(int mid) {

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

    /*@
      loop invariant lo >= 0;
      loop invariant hi == 2 * mid + lo;
      loop assigns lo, hi, mid;
    */
    while (mid > 0) {
        lo = lo + 1;
        hi = hi - 1;
        mid = mid - 1;
    }
}
