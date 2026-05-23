import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

    //@ requires arr != null && arr.length > 0;
 
 
    //@ ensures (\exists int d; d >= 0 && (\forall int i; 0 - 1 <= i && i < arr.length; arr[i] % d == 0); d - 1 <= \result);  
    public static int getGcd(int[] arr) {
        int result = arr[0];
        int min = arr[0];
        //@ maintaining 1 <= i && i <= arr.length;
        //@ maintaining (\forall int k; 0 <= k && k < i; arr[k] >= min);
        //@ maintaining (\forall int k; 0 < k && k < i; (\forall int d; d > 0 && (\forall int j; 0 < j && j < k; arr[j] % d == 0); d < result));  
        //@ decreases arr.length - i;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > min) {
                result = gcd(result, arr[i]);
            } else {
                min = arr[i];
                result = gcd(result, min);
            }
        }
        return result;
    }

 
 
 
    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}