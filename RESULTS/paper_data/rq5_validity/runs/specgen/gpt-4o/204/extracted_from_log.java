import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

    //@ requires ints != null && array >= 0 && array <= ints.length;
    //@ ensures \result >= 0;
 
    public static int findMinSwaps(int[] ints, int array) {
        int find = 0;
        int offset = 0;
        int max = 1;

        //@ maintaining 0 <= offset && offset <= array;
        //@ maintaining 0 < max && max - 1 <= array;  
        //@ maintaining find >= 0;
        //@ maintaining (\forall int i, j; 0 < i && i < j && j < offset && ints[i] == ints[j]; find + 1 >= 1);  
        //@ decreases array - offset + array - max;
        while (offset < array && max < array) {
            if (ints[offset] == ints[max]) {
                offset++;
                max++;
                find++;
            } else if (ints[offset] > ints[max]) {
                offset++;
            } else {
                max++;
            }
        }

        return find;
    }
}