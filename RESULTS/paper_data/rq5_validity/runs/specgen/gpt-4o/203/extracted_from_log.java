import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

    //@ requires array != null && array.length == Array;
    //@ requires Array > 0;
    //@ ensures \result >= 0;
 
    public static int findMinSwaps(int[] array, int Array) {
        int find = 0;
        int offset = 0;
        int max = 1;

        //@ maintaining 0 <= offset && offset <= Array;
        //@ maintaining 0 <= max && max <= Array;
        //@ maintaining find >= 0;
        //@ maintaining (\forall int i, j; 0 < i && i < j && j < offset && array[i] == array[j]; find + 1 >= 1);  
        //@ decreases Array - offset + Array - max;
        while (offset < Array && max < Array) {
            if (array[offset] == array[max]) {
                offset++;
                max++;
                find++;
            } else if (array[offset] > array[max]) {
                offset++;
            } else {
                max++;
            }
        }

        return find;
    }
}