class IsOneBitCharacter {
    /*@ requires bits != null;
      @ requires bits.length >= 1;
      @ requires (\forall int idx; 0 <= idx && idx < bits.length; bits[idx] == 0 || bits[idx] == 1);
      @
      @ // The result is true iff the last character is decoded as a one-bit character.
      @ // Equivalently: the last bit is 0 and the number of consecutive 1's
      @ // immediately before the last bit is even.
 
      @   (bits[bits.length - 1] == 0 &&
      @    (\exists int c; 0 <= c && c <= bits.length - 1 &&
      @        (\forall int j; bits.length - 1 - c <= j && j <= bits.length - 2 ==> bits[j] == 1) &&
      @        (bits.length - 2 - c < 0 || bits[bits.length - 2 - c] == 0) &&
      @        c % 2 == 0));
      @*/
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length, i = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int k; 0 <= k && k < bits.length ==> bits[k] == 0 || bits[k] == 1);
        //@ decreases n - i;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
}
