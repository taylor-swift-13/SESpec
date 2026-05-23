class IsOneBitCharacter {
    /*@ 
      @ requires bits != null;
      @ requires (\forall int k; 0 <= k && k < bits.length; bits[k] == 0 || bits[k] == 1);
      @ // Standard setting for this problem assumes the last bit is 0 when non-empty
      @ requires bits.length == 0 || bits[bits.length - 1] == 0;
      @ ensures bits.length == 0 ==> \result == false;
      @ ensures bits.length > 0 ==> 
      @   (\result <==> (bits[bits.length - 1] == 0 &&
      @     (\exists int t; 0 <= t && t <= bits.length - 1;
      @       (\forall int k; t <= k && k < bits.length - 1; bits[k] == 1) &&
      @       (t == 0 || bits[t - 1] == 0) &&
      @       (((bits.length - 1) - t) % 2 == 0))));
      @*/
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length, i = 0;
        //@ maintaining n == bits.length;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int k; 0 <= k && k < bits.length; bits[k] == 0 || bits[k] == 1);
        //@ decreases (n - 1) - i;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
}