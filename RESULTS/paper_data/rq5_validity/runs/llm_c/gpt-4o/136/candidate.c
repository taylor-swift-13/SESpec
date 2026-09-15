/*@
    requires x >= 0;
    ensures \result >= 0;
    ensures (long)\result * \result <= x < (long)(\result + 1) * (\result + 1);
    assigns \nothing;
*/
int mySqrt(int x) {

        int l = 0, r = x, ans = -1;
        /*@
        loop invariant 0 <= l && l <= x + 1;
        loop invariant -1 <= r && r <= x;
        loop invariant -1 <= ans && ans < l;
        loop invariant \forall integer k; 0 <= k < l ==> (long)k * k <= x;
        loop invariant \forall integer k; r < k <= x ==> (long)k * k > x;
        loop assigns l, r, ans;
        loop variant r - l;
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
