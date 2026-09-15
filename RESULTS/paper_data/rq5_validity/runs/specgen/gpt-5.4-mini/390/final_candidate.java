import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class PermutationCoefficient {

    //@ requires n >= 0 && k >= 0 && k <= n;
 
    public static int permutationCoefficient(int n, int k) {
        int res = 1;
        int i = 1;
        //@ maintaining 1 <= i && i <= k + 1;
 
        //@ decreases k - i + 1;
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
    }
}
