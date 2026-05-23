import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxPrimeFactors {

    //@ requires num > 0;
    //@ ensures (\forall int p; p > 1 && p <= num; (num % p == 0 && (\forall int d; 2 <= d && d < p; p % d != 0)) ==> \result >= p);  
    //@ ensures (\exists int p; p > 1 && p <= num; (num % p == 0 && (\forall int d; 2 <= d && d < p; p % d != 0)) ==> \result == p);
    public static int maxPrimeFactors(int num) {
        int result = 0;
        //@ maintaining 2 <= c && c <= num + 1;
        //@ maintaining (\forall int p; 2 <= p && p < c; (num % p == 0 && (\forall int d; 2 <= d && d < p; p % d != 0)) ==> result >= p);
        //@ maintaining (\forall int p; 2 < p && p < c; (num % p == 0 && (\exists int d; 2 < d && d < p; p % d != 0)) ==> result == p);  
        //@ decreases num - c + 1;
        for (int c = 2; c <= num; c++) {
            //@ maintaining num >= 0;
            //@ maintaining result >= 0;
            //@ maintaining num % c == 0 ==> result == c;
            //@ decreases num;
            while (num % c == 0) {
                result = c;
                num /= c;
            }
        }
        return result;
    }
}