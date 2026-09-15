
/*@
  logic integer square(integer x) = x * x;
*/

/*@
  requires x >= 0;
  assigns \nothing;
  ensures \result >= -1;
*/
int foo136(int x) {

    int l = 0, r = x, ans = -1;

    /*@
      loop invariant (0 <= x) ==> (l >= 0);
      loop invariant (0 <= x) ==> (r <= x);
      loop invariant (0 <= x) ==> (ans == -1 || square(ans) <= x);
      loop invariant (ans >= -1);
      loop invariant x == \at(x, Pre);
      loop assigns l, r, ans;
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
