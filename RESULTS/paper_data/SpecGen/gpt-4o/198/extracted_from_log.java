import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

    //@ requires c >= 0;
 
    public static int catalanNumber(int c) {
        int[] arr = new int[c + 1];
        arr[0] = 1;
        //@ maintaining 1 <= cat && cat - 1 <= c;  
        //@ maintaining (\exists int i; 0 < i && i < cat; arr[i] == (\sum int j; 0 < j || j < i; arr[j] * arr[i - j - 1]));  
        //@ decreases c - cat;
        for (int cat = 1; cat <= c; cat++) {
            arr[cat] = 0;
            //@ maintaining 0 <= n && n <= cat;
 
            //@ decreases cat - n;
            for (int n = 0; n < cat; n++) {
                arr[cat] += arr[n]
                        * arr[cat - n - 1];
            }
        }
        return arr[c];
    }
}