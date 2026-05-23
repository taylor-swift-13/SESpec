import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

    //@ requires n > 0 && k > 0 && k <= n;
    //@ ensures (\exists int i; 1 <= i && i <= n; \result == i && ((i % 2 != 0 && (\num_of int j; 1 <= j && j <= n && j % 2 != 0; true) == k) || (i % 2 == 0 && (\num_of int j; 1 <= j && j <= n && j % 2 == 0; true) == k)));
    //@ ensures \result == 0 <==> k > n;
    public static int getNumber(int n, int k) {
        int a[] = new int[n];
        int b[] = new int[n];
        int i, count = 0;

        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int j; 0 <= j && j < i; a[j] == j + 1);
        //@ decreases n - i;
        for (i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int j; 0 <= j && j < i; b[j] == a[j]);
 
        //@ decreases n - i;
        for (i = 0; i < n; i++) {
            b[i] = a[i];
            if (a[i] % 2 != 0) {
                count++;
                if (count == k) {
                    return a[i];
                }
            }
        }

        //@ maintaining 0 <= i && i <= n;
        //@ maintaining (\forall int j; 0 <= j && j < i; b[j] == a[j]);
        //@ maintaining count == (\num_of int j; 0 - 1 <= j && j <= i && a[j] % 2 == 0; true) + (\num_of int j; 0 < j && j < n && a[j] % 2 != 0; true);  
        //@ decreases n - i;
        for (i = 0; i < n; i++) {
            b[i] = a[i];
            if (a[i] % 2 == 0) {
                count++;
                if (count == k) {
                    return a[i];
                }
            }
        }

        return 0;
    }
}