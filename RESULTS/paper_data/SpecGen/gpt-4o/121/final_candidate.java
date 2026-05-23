class IsOneBitCharacter {
    //@ requires bits != null && bits.length > 0;
    //@ requires (\forall int i; 0 <= i && i < bits.length; bits[i] == 0 || bits[i] == 1);
 
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length, i = 0;
        //@ maintaining 0 <= i && i - 1 <= n - 1;  
        //@ maintaining (\forall int k; 0 < k && k < i; bits[k] == 1 ==> k + 1 <= i);  
        //@ decreases n - i;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
}
