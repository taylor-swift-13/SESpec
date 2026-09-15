class PowerOfFourLoop {
    /*@ public normal_behavior
 
      @                           && (\old(n) & (\old(n) - 1)) == 0
      @                           && (\old(n) & 0x55555555) != 0);
      @   ensures \old(n) <= 0 ==> !\result;
      @*/
    public boolean isPowerOfFour(int n) {
        if(n <= 0) {
            return false;
        }
        //@ maintaining n > 0;
 
        //@ decreases n;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
}
