import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Search {

    //@ requires arr != null && arr.length == n && n > 0;
    //@ requires (\forall int i; 0 <= i && i < n - 1; arr[i] == arr[i + 1] ==> i % 2 == 0);
    //@ ensures (\exists int i; 0 <= i && i < n; \result == arr[i] && (\forall int j; 0 <= j && j < n && j != i; arr[j] != arr[i]));
    //@ ensures (\forall int i; 0 <= i && i < n; (\forall int j; 0 <= j && j < n && j != i; arr[i] != arr[j]) ==> \result == arr[i]);
    public static int search(int[] arr, int n) {
        int i = 0;
        //@ maintaining 0 <= i && i <= n - 1;
        //@ maintaining (\forall int k; 0 <= k && k < i; arr[k] == arr[k + 1]);
        //@ maintaining (\forall int k; 0 <= k && k < i; (\forall int j; k + 1 <= j && j < n; arr[k] != arr[j]));
        //@ decreases n - i;
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                //@ assert (\forall int j; i + 1 <= j && j < n; arr[i] != arr[j]);
                return arr[i];
            }
        }
        //@ assert (\forall int j; 0 <= j && j < n - 1; arr[n - 1] != arr[j]);
        return arr[n - 1];
    }
}