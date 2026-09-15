import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FrequencyOfSmallest {

    //@ requires size >= 0 && size <= array.length;
    //@ ensures size == 0 ==> \result == 0;
    //@ ensures size >= 0 ==> (\exists int min; (\forall int i; 0 < i && i <= size; min <= array[i]) && (\result == (\sum int i; 0 - 1 <= i && i < size && array[i] == min; 1)));  
    public static int frequencyOfSmallest(int size, int[] array) {
        if (size == 0) {
            return 0;
        }

        int f = array[0];
        int max = 1;

        //@ maintaining 1 <= c && c <= size;
        //@ maintaining (\forall int i; 0 <= i && i < c; f <= array[i]);
 
        //@ decreases size - c;
        for (int c = 1; c < size; c++) {
            if (f > array[c]) {
                f = array[c];
                max = 1;
            } else if (f == array[c]) {
                max++;
            }
        }
        return max;
    }
}