import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class PermutationCoefficient {

    /*@ 
      @ requires k >= 0;
      @ ensures \result == (\product int j; 0 <= j && j < k; (n - j));
      @ ensures k == 0 ==> \result == 1;
      @ ensures k > n ==> \result == 0;
      @*/
    public static int permutationCoefficient(int n, int k) {
        int res = 1;
        int i = 1;
        //@ maintaining 1 <= i && i <= k + 1;
        //@ maintaining res == (\product int t; 1 <= t && t < i; (n - t + 1));
        //@ decreases k - i + 1;
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
    }
}