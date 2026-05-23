class PowerOfThree {
    /*@ 
      @ ensures (n < 0) ==> (\result == false);  
      @ ensures (n == 1) ==> (\result == true);
      @ ensures \result ==> (n >= 0);  
      @*/
    public boolean isPowerOfThree(int n) {
        int temp = n;
        /*@ 
          @ maintaining (temp == n) || (temp != 0 ==> n % temp == 0);
          @ maintaining temp == 0 || (temp % 3 == 0 || temp % 3 != 0);
          @*/
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
    }
}
