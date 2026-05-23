int mySqrt(int x);

/*@
  behavior nonneg:
    assumes x >= 0;
    assigns \nothing;
    ensures 0 <= \result <= x;
    ensures (long)\result * (long)\result <= (long)x;
    ensures (long)(\result + 1) * (long)(\result + 1) > (long)x;
  behavior neg:
    assumes x < 0;
    assigns \nothing;
    ensures \result == -1;
  complete behaviors nonneg, neg;
  disjoint behaviors nonneg, neg;
*/
int mySqrt(int x) {

        int l = 0, r = x, ans = -1;
        /*@
            loop invariant 0 <= l && l <= x + 1;
            loop invariant -1 <= r && r <= x;
            loop invariant l <= r + 1;
            loop invariant (\forall integer y; 0 <= y < l ==> (long)y * (long)y <= (long)x);
            loop invariant (\forall integer y; r < y <= x ==> (long)y * (long)y > (long)x);
            loop invariant -1 <= ans && ans <= x;
            loop assigns l, r, ans;
            loop variant r - l + 1;
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
