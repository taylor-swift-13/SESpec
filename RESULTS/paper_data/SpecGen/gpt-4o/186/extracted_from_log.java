import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

    //@ requires size >= 0 && a.length >= size;
    //@ ensures \result == 0 <==> size == 0;
    //@ ensures size > 0 ==> (\exists int i; 0 <= i && i < size; a[i] == (\min int j; 0 <= j && j < size; a[j]) && \result == (\sum int k; 0 <= k && k < size && a[k] == a[i]; 1));
    public static int frequencyOfSmallest(int size, int[] a) {
        if (size == 0) {
            return 0;
        }

        int f = a[0];
        int total = 1;

        //@ maintaining 1 <= c && c <= size;
        //@ maintaining (\forall int i; 0 - 1 <= i && i <= c; f == (\min int j; 0 < j && j <= c; a[j]));  
 
        //@ decreases size - c;
        for (int c = 1; c < size; c++) {
            if (f > a[c]) {
                f = a[c];
                total = 1;
            } else if (f == a[c]) {
                total++;
            }
        }
        return total;
    }
}