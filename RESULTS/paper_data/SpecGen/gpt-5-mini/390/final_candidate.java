import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class PermutationCoefficient {

    /*@ public normal_behavior
      @ ensures \result == (\product int j; 1 <= j && j <= k; n - j + 1);
      @*/
    public static int permutationCoefficient(int n, int k) {
        int res = 1;
        int i = 1;
 
 
 
          @*/
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
    }
}
