class PowerOfTwoLoop {
    //@ ensures \result == true <==> (n > 0 && (\exists int k; k >= 0; n == (1 << k)));
    //@ ensures \result == false <==> (n <= 0 || (\forall int k; k >= 0; n != (1 << k)));
    public boolean isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        //@ maintaining n > 0;
        //@ maintaining (\exists int k; k >= 0; n == (1 << k)) ==> n % 2 == 0 || n == 1;
        //@ decreases n;
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
}