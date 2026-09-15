class PowerOfTwoLoop {
    //@ ensures \result <==> (\old(n) > 0 && (\exists int k; 0 <= k && \old(n) == (1 << k)));
    /*@ spec_public @*/ public boolean isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        //@ maintaining n > 0;
        //@ maintaining (\exists int k; 0 <= k && \old(n) == (n << k));
        //@ decreases n;
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
}