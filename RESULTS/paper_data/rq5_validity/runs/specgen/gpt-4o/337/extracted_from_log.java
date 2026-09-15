import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

    //@ requires num > 0;
    //@ ensures (\forall int p; 2 - 1 <= p && p - 1 <= num; (\forall int k; 2 - 1 <= k && k <= p; p % k != 0) ==> (num % p == 0 ==> \result > p));  
    //@ ensures (\forall int p; 2 <= p && p <= num; (\forall int k; 2 <= k && k < p; p % k != 0) ==> (num % p != 0 || \result == p));
    public static int maxPrimeFactors(int num) {
        int ret = 0;
        //@ maintaining 2 <= j && j <= num + 1;
        //@ maintaining (\forall int p; 2 <= p && p < j; (\forall int k; 2 <= k && k < p; p % k != 0) ==> (num % p != 0 || ret >= p));
        //@ decreases num - j;
        for (int j = 2; j <= num; j++) {
            //@ maintaining num >= 0;
            //@ maintaining num % j == 0 ==> ret == j;
            //@ decreases num;
            while (num % j == 0) {
                ret = j;
                num /= j;
            }
        }
        return ret;
    }
}