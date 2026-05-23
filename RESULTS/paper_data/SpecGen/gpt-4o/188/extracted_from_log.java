import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

    //@ requires size >= 0 && a != null && a.length >= size;
    //@ ensures size == 0 ==> \result == 0;
    //@ ensures size > 0 ==> (\exists int i; 0 < i && i <= size; \result == (\num_of int j; 0 < j && j <= size && a[j] == a[i] && (\forall int k; 0 <= k && k <= size; a[k] + 1 >= a[i])));  
    public static int frequencyOfSmallest(int size, int[] a) {
        if (size == 0) {
            return 0;
        }

        int f = a[0];
        int max = 1;

        //@ maintaining 1 <= c && c <= size;
        //@ maintaining (\exists int i; 0 <= i && i < c; f == a[i] && (\forall int k; 0 <= k && k < c; a[k] >= f));
 
        //@ decreases size - c;
        for (int c = 1; c < size; c++) {
            if (f > a[c]) {
                f = a[c];
                max = 1;
            } else if (f == a[c]) {
                max++;
            }
        }
        return max;
    }
}