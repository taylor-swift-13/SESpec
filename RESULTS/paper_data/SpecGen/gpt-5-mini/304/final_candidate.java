import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

    /*@ requires n >= 1;
 
      @ ensures (\exists int[] seq; seq != null && seq.length == n + 1 ||  
      @          seq[0] == 0 &&
      @          (n >= 1 ==> seq[1] == 1) &&
      @          (\forall int k; 2 <= k && k <= n; seq[k] == (2 * seq[k-1] + seq[k-2]) % 1000000000) &&
      @          seq[n] == \result);
      @*/
    public static int getPell(int n) {
        int [] pell = new int[n + 1];
        pell[0] = 0;
        pell[1] = 1;
 
 
        //@                (j == 0 ==> pell[j] == 0) &&
        //@                (j == 1 ==> pell[j] == 1) &&
        //@                (j >= 2 ==> pell[j] == (2 * pell[j-1] + pell[j-2]) % 1000000000));
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
        return pell[n];
    }
}
