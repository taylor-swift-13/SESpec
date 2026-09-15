
/*@
  logic integer square(integer x) = x * x;
*/

/*@
  predicate is_valid_state(integer ans, integer l, integer r, integer x, integer x_pre) =
    (ans == -1 && r == x_pre && l == 0 && x == x_pre) ||
    (ans != -1 && square(ans) <= x && square(ans + 1) > x && l > r && x == x_pre);
*/

int foo136(int x) {

    int l = 0, r = x, ans = -1;

    /*@
      loop invariant (0 <= x) ==> (l >= 0);
      loop invariant (0 <= x) ==> (r <= x);
      loop invariant (0 <= x) ==> (ans == -1 || square(ans) <= x);
      loop invariant x == \at(x, Pre);
      loop assigns ans, l, r;
    */
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long) mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}
