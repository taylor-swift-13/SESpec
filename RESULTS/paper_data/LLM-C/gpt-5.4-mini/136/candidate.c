/*@
    requires x >= 0;
    ensures \result >= 0;
    ensures (long)\result * (long)\result <= x;
    ensures \result == 46340 || (long)(\result + 1) * (long)(\result + 1) > x;
    assigns \nothing;
*/
int mySqrt(int x);

int mySqrt(int x) {

        int l = 0, r = x, ans = -1;
        /*@
            loop invariant 0 <= l;
            loop invariant -1 <= ans;
            loop invariant ans == -1 || (long)ans * (long)ans <= x;
            loop invariant 0 <= r + 1;
            loop invariant l <= x + 1;
            loop invariant r <= x;
            loop invariant l <= r + 1;
            loop invariant ans == -1 || ans <= r + 1;
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
