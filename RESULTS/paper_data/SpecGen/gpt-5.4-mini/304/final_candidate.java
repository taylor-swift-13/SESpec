import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

    //@ requires n >= 1;
 
 
    //@ ensures (\exists int[] pell; pell.length == n + 1 &&
    //@          pell[0] == 0 && pell[1] == 1 &&
    //@          (\forall int i; 2 <= i && i <= n;
    //@             pell[i] == (2 * pell[i - 1] + pell[i - 2]) % 1000000000) &&
    //@          \result == pell[n]);
    public static int getPell(int n) {
        int [] pell = new int[n + 1];
        pell[0] = 0;
        pell[1] = 1;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining pell.length == n + 1;
        //@ maintaining pell[0] == 0;
        //@ maintaining pell[1] == 1;
 
        //@                pell[j] == (2 * pell[j - 1] + pell[j - 2]) % 1000000000);
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
        return pell[n];
    }
}
