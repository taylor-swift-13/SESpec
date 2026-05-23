class MySqrt {
    //@ requires x >= 0;
    //@ ensures \result + 1 >= 0;  
    //@ ensures ((long)\result * (long)\result - 1 <= x);  
 
    public int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        //@ maintaining 0 <= l && l <= x + 1;
        //@ maintaining -1 <= ans && ans <= x;
        //@ maintaining ans == -1 || ((long)ans * (long)ans <= x);
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
