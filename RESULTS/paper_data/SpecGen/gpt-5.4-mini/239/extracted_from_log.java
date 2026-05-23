import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

    /*@
      @ requires ar != null;
      @ requires 0 <= n && n <= ar.length;
      @ ensures 1 <= \result && \result <= n + 1;
      @ ensures (\exists int i; 1 - 1 <= i && i <= \result; (\forall int j; 0 <= j && j <= n; ar[j] == i));  
      @*/
    public static int findMissing(int[] ar, int n) {
        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        /*@
          @ maintaining 1 <= i && i - 1 <= n;  
          @ maintaining 1 <= missing && missing <= i;
          @ decreases n - i;
          @*/
        for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
        return missing;
    }
}