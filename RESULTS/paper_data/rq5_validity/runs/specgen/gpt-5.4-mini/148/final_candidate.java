class PowerOfTwoLoop {
    //@ ensures \result <==> (n > 0 && (\exists int k; k >= 0; n == (1 << k)));
    public boolean isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        //@ maintaining n > 0;
 
        //@ decreases n;
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
}
