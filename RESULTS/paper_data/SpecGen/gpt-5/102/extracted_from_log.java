class DigitRoot {
    /*@
      @ requires num >= 0;
      @ ensures (\old(num) == 0) ==> (\result == 0);
      @ ensures (\old(num) > 0) ==> (1 <= \result && \result <= 9 && \result % 9 == \old(num) % 9);
      @*/
    public int digitRoot(int num) {
        /*@ 
          @ maintaining num >= 0;
          @ decreases num;
          @*/
        while (num >= 10) {
            int sum = 0;
            /*@ 
              @ maintaining sum >= 0 && num >= 0;
              @ decreases num;
              @*/
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
}