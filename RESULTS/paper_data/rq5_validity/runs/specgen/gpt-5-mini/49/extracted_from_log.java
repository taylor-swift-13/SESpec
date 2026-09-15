class SVCOMP_linear_0086__176 {
    /*@ 
      @ requires true;
      @ // If k >= 0 the loop executes 2*k iterations and increments i and j each exactly k times.
 
      @ // If k < 0 the loop body is not executed and i and j remain unchanged.
      @ ensures k < 0  ==> (i == \old(i) && j == \old(j));
      @*/
    static void foo176(int i, int j, int k) {

        int n;
        int b;

        n = 0;
        b = 1;

        //@ maintaining n >= 0;
        //@ maintaining (k < 0) ==> (n == 0);
        //@ maintaining (k >= 0) ==> (n <= 2 * k);
        //@ maintaining i + j == \old(i) + \old(j) + n;
        //@ maintaining (n % 2 == 0 ==> b == 1) && (n % 2 == 1 ==> b == 0);
        //@ maintaining b == 0 || b == 1;
        //@ decreases 2*k - n;
        while(n < (2 * k)){
            n = n + 1;
            if(b == 1){
                b = 0;
                i = i + 1;
            }
            else{
                b = 1;
                j = j + 1;
            }
        }

    }
}