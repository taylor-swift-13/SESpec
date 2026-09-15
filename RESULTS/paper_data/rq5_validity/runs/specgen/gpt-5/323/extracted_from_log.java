import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

    /*@
      @ requires n >= 1;
      @ ensures (n == 1) ==> (\result == 1);
      @ ensures (n >= 2) ==> (\result == (\num_of int i; 2 <= i && i*i <= n && n % i == 0));
      @ ensures \result >= 0;
      @*/
    public static int countFac(int n) {
        int count = 0;
        if (n == 1) return 1;
        /*@
          @ maintaining i >= 2;
          @ maintaining count == (\num_of int k; 2 <= k && k < i && k*k <= n && n % k == 0);
          @ maintaining count >= 0;
          @ decreases n - i;
          @*/
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
        return count;
    }
}