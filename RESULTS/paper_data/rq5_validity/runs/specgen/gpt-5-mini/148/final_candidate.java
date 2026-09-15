class PowerOfTwoLoop {
    /*@ 
      @ requires true;
      @ ensures \result <==> (\old(n) > 0 && (\old(n) & (\old(n) - 1)) == 0);
      @*/
    public boolean isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        /*@ 
          @ // Invariant: the current n remains positive, and it always divides the original value.
          @ // The quotient \old(n)/n is always a power of two.
          @ maintaining \old(n) > 0;
          @ maintaining n > 0;
          @ maintaining \old(n) % n == 0;
          @ maintaining ((\old(n) / n) & (\old(n) / n - 1)) == 0;
          @ decreases \old(n) / n;
          @*/
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
}