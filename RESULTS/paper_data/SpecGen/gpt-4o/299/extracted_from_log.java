import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

    //@ requires data != null && data.length > 0 && array == data.length;
    //@ ensures 0 <= \result && \result < data.length;
    //@ ensures (\result == 0 || data[\result] >= data[\result - 1]) && (\result == data.length - 1 || data[\result] >= data[\result + 1]);
    public static int findPeak(int[] data, int array) {
        int i = 0, top = array - 1;
        //@ maintaining 0 <= i && i <= top && top < array;
        //@ maintaining (\exists int k; i < k && k < top; (\forall int j; i < j && j <= k; data[j] - 1 <= data[j + 1]) && (\forall int j; k < j && j < top; data[j] >= data[j + 1]));  
        //@ decreases top - i;
        while (i < top) {
            int p = i + (top - i) / 2;
            if (data[p] < data[p + 1]) {
                i = p + 1;
            } else {
                top = p;
            }
        }
        return i;
    }
}