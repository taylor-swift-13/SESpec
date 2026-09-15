class SVCOMP_linear_0092__181 {
    /*@ 
 
      @ ensures \old(k) < 0 ==> (i == \old(i) && j == \old(j));
      @*/
    static void foo181(int i, int j, int k) {

        int n;
        int b;

        n = 0;
        b = 0;

        //@ maintaining 0 <= n;
        //@ maintaining (\old(k) >= 0) ==> n <= 2 * \old(k);
        //@ maintaining b == n % 2;
        //@ maintaining i == \old(i) + n/2;
        //@ maintaining j == \old(j) + (n + 1)/2;
        //@ decreases 2 * \old(k) - n;
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