class IsOneBitCharacter {
    //@ requires bits != null;
    //@ ensures \result <==> (\exists int k; 0 <= k && k < bits.length && k == bits.length - 1;
    //@                        true);
 
    //@                        (\exists int i; 0 <= i && i < n; i == n - 1 &&
    //@                         (\forall int j; 0 <= j && j < i; bits[j] == 0)));
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length, i = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining i == 0 || (\exists int t; 0 <= t && t < i; true);
        //@ maintaining i < n ==> (\forall int j; 0 <= j && j < i; bits[j] == 0 || bits[j] == 1);
        //@ decreases n - 1 - i;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
}
