import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MinOps {

    /*@
      @ requires arr != null;
      @ requires 1 <= n && n <= arr.length;
      @ requires k > 0;
      @ assignable \nothing;
      @ ensures \result == -1 || \result >= 0;
      @*/
    public static int minOps(int[] arr, int n, int k) {
        int max1 = arr[0];
        //@ maintaining 1 <= i && i <= n;
        //@ decreases n - i;
        for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
        int res = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            if ((max1 - arr[i]) % k != 0) {
                return -1;
            } else {
                res += (max1 - arr[i]) / k;
            }
        }
        return res;
    }
}