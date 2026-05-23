import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

    //@ requires n >= 1;
    //@ ensures (\exists int[] t; t != null && t.length == n + 1
    //@            && t[0] == 0 && t[1] == 1
    //@            && (\forall int i; 2 <= i && i <= n; t[i] == (2 * t[i - 1] + t[i - 2]) % 1000000000)
    //@            && \result == t[n]);
    /*@ spec_public @*/ public static int getPell(int n) {
        int [] pell = new int[n + 1];
        pell[0] = 0;
        pell[1] = 1;
        //@ maintaining pell != null && pell.length == n + 1;
        //@ maintaining 2 <= i && i <= n;
        //@ maintaining pell[0] == 0 && pell[1] == 1;
        //@ maintaining (\forall int k; 2 <= k && k < i; pell[k] == (2 * pell[k - 1] + pell[k - 2]) % 1000000000);
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
        return pell[n];
    }
}