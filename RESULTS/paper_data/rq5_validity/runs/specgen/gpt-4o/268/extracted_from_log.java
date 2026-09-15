import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

    //@ requires count >= 0 && w > 0;
 
    //@ ensures (\exists int[] div; div.length == count + 1 && div[0] == 1 && (count > 1 ==> div[1] == w) && (count > 2 ==> div[2] == w * w) || div[count] == \result);  
    public static int countNoOfWays(int count, int w) {
        int MOD = 1000000007;
        int div[] = new int[count + 1];
        div[0] = 1;
        if (count >= 1) {
            div[1] = w;
        }
        if (count >= 2) {
            div[2] = (int)(((long)w * w) % MOD);
        }

        for (int d = 3; d <= count; d++) {
            //@ assume d - 1 >= 0 && d - 2 >= 0;
            div[d] = (int)(((long)(w - 1) * (div[d - 1] + div[d - 2])) % MOD);
        }
        return div[count];
    }
}