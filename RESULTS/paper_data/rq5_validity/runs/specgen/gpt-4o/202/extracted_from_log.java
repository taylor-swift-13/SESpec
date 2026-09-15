import java.io.*;
import java.lang.*;
import java.math.*;

class FindMinSwaps {

    //@ requires ints != null && array >= 0 && array <= ints.length;
    //@ ensures \result >= 0;
    //@ ensures (\forall int i; 0 < i && i < array; (\exists int j; i < j && j < array; ints[i] == ints[j]) ==> \result >= 0);  
    public static int findMinSwaps(int[] ints, int array) {
        int find = 0;
        int min = 0;
        int offset = 1;

        //@ maintaining 0 <= min && min <= array;
        //@ maintaining 0 < offset && offset - 1 <= array;  
        //@ maintaining find >= 0;
        //@ maintaining (\forall int i; 0 < i && i < min; (\exists int j; i < j && j < offset; ints[i] == ints[j]) ==> find >= 0);  
        //@ decreases array - min + array - offset;
        while (min < array && offset < array) {
            if (ints[min] == ints[offset]) {
                min++;
                offset++;
                find++;
            } else if (ints[min] > ints[offset]) {
                min++;
            } else {
                offset++;
            }
        }

        return find;
    }
}