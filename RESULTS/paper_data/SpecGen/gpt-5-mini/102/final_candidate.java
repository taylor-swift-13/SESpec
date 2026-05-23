class DigitRoot {
    /*@ 
      requires num >= 0;
      ensures 0 <= \result && \result <= 9;
      ensures (\old(num) == 0) ==> \result == 0;
      ensures (\old(num) > 0) ==> \result == 1 + ((\old(num) - 1) % 9);
    @*/
    public int digitRoot(int num) {
        /*@ 
          maintaining num >= 0;
          decreases num;
        @*/
        while (num >= 10) {
            int sum = 0;
            /*@ 
              maintaining sum >= 0;
              maintaining num >= 0;
              decreases num;
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