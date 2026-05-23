import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Sum {

    //@ requires n >= 0;
 
    //@ ensures \result == (\sum int i; 2 <= i && i <= n && (\exists int k; 2 <= k && k <= i; i % k != 0); i);  
    public static int sum(int n) {
        int[] sumOfPrimeDivisors = new int[n + 1];
        //@ assume 1 < sumOfPrimeDivisors.length;
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;

        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining (\forall int k; 2 <= k && k < i; (\forall int j; k <= j && j <= n && j % k == 0; sumOfPrimeDivisors[j] >= k));
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                //@ maintaining i <= j && j <= n + 1;
                //@ maintaining (\forall int k; i <= k && k < j; sumOfPrimeDivisors[k] >= i);
                //@ decreases n - j + 1;
                for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        return sumOfPrimeDivisors[n];
    }
}