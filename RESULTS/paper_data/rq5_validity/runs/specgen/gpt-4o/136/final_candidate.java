class MySqrt {
    //@ ensures \result >= 0 && \result * \result <= x && (\result + 1) * (\result + 1) > x;
    public int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        //@ maintaining 0 <= l && l <= x && 0 <= r && r <= x && -1 <= ans && ans <= r;
        //@ maintaining ans >= 0 ==> ans * ans <= x;
        //@ maintaining (\forall int i; ans < i && i < r; i * i > x);  
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
