
/*@
  assigns \nothing;

  behavior neg:
    assumes x < 0;
    ensures \result == -1;

  behavior pos:
    assumes x >= 0;
    ensures \result >= 0;

  complete behaviors;
  disjoint behaviors;
*/
int foo136(int x) {
    if (x < 0) return -1;

    int l = 0, r = x, ans = 0;

    /*@
      loop invariant 0 <= l <= r + 1;
      loop invariant 0 <= ans;
      loop assigns l, r, ans;
    */
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long)mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}
