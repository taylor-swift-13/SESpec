class MySqrt {
    //@ requires x >= 0;
    //@ ensures 0 <= \result && ((long)\result) * \result <= x && ((long)(\result + 1)) * (\result + 1) > x;
    public int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        //@ maintaining 0 <= l && -1 <= r && l <= r + 1 && r <= x;
        //@ maintaining (\forall int k; 0 <= k && k < l; ((long)k) * k <= x);
        //@ maintaining (\forall int k; r < k && k <= x; ((long)k) * k > x);
        //@ maintaining -1 <= ans && (ans == -1 || ((long)ans) * ans <= x) && ans < l;
        //@ decreases r - l + 1;
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
}