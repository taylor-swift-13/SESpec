import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

    //@ requires ar != null && ar.length == n;
    //@ requires (\forall int i; 0 <= i && i < n; ar[i] > 0 && ar[i] <= n);
    //@ ensures (\forall int i; 1 <= i && i <= n; (\exists int j; 0 <= j && j < n; ar[j] == i) ==> \result != i);
    //@ ensures (\forall int i; 1 <= i && i <= n; (\forall int j; 0 <= j && j < n; ar[j] != i) ==> \result == i);
    public static int findMissing(int[] ar, int n) {
        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
        //@ maintaining 1 <= i && i <= n + 1;
        //@ maintaining (\forall int k; 1 <= k && k < i; (\forall int j; 0 <= j && j < n; ar[j] == k) ==> missing != k);  
        //@ maintaining (\forall int k; 1 <= k && k < i; (\forall int j; 0 <= j && j < n; ar[j] != k) ==> missing == k);
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
        return missing;
    }
}