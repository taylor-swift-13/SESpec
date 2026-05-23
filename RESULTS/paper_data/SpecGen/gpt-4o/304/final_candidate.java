import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

    //@ requires n >= 0;
    //@ ensures \result == (n == 0 ? 0 : (n == 1 ? 1 : (2 * getPell(n - 1) + getPell(n - 2)) % 1000000000));
    public static int getPell(int n) {
        int [] pell = new int[n + 1];
        pell[0] = 0;
        pell[1] = 1;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining pell[0] == 0 && pell[1] == 1;
        //@ maintaining (\forall int k; 2 <= k && k < i; pell[k] == (2 * pell[k - 1] + pell[k - 2]) % 1000000000);
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
        return pell[n];
    }
}