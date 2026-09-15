class PowerOfFourLoop {
    //@ ensures n <= 0 ==> \result == false;
 
    public boolean isPowerOfFour(int n) {
        if(n <= 0) {
            return false;
        }
        //@ maintaining n > 0;
        //@ maintaining (\exists int k; k >= 0; n == Math.pow(4, k)) || (\forall int k; k >= 0; n != Math.pow(4, k));
        //@ decreases n;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
}
