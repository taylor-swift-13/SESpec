import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

    //@ requires array != null && array.length == count;
    //@ requires count >= 0;
    //@ requires (\forall int i; 0 <= i && i < count - 1; array[i] <= array[i + 1] || array[count - 1] <= array[0]);
    //@ ensures \result >= 0 && \result <= count;  
    //@ ensures (\forall int i; 0 <= i && i < count; array[(\result + i) % count] <= array[(\result + i + 1) % count]);
    public static int countRotation(int[] array, int count) {
        if (count == 0) {
            return 0;
        }
        int r = 0, top = count - 1;
        //@ maintaining 0 <= r && r <= top && top < count;
        //@ maintaining (\forall int i; 0 <= i && i < count; array[(r + i) % count] <= array[(r + i + 1) % count]);
        //@ decreases top - r;
        while (r < top) {
            if (array[r] < array[top]) {
                return r + 1;
            }
            int end = (r + top) / 2;
            if (array[end] > array[r]) {
                r = end;
            } else {
                top = end;
            }
        }
        return r + 1;
    }
}