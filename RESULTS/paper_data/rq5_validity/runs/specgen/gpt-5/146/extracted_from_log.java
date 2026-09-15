class PowerOfFourLoop {
    //@ ensures \result <==> (\old(n) > 0 && (\exists int k; 0 <= k && k <= 15; \old(n) == (1 << (2*k))));
    public boolean isPowerOfFour(int n) {
        /*@ ghost int n0 = n; @*/
        if(n <= 0) {
            return false;
        }
        /*@
          @ maintaining n > 0 && n <= n0 && n0 % n == 0;
          @ decreases n;
          @*/
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
}