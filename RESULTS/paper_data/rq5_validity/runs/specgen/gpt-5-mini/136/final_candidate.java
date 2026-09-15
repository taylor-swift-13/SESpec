class MySqrt {
    /*@ public normal_behavior
      @   requires x >= 0;
      @   ensures 0 <= \result && \result <= x;
 
      @   ensures (long)(\result + 1) * (\result + 1) > x;
      @*/
    /*@ spec_public @*/ public int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        //@ maintaining 0 <= l && l <= x + 1;
        //@ maintaining -1 <= r && r <= x;
        //@ maintaining -1 <= ans && ans <= x;
        //@ maintaining (\forall int t; 0 <= t && t < l; (long)t * t <= x ==> t <= ans);
        //@ maintaining (\forall int t; r < t && t <= x; (long)t * t > x);
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
