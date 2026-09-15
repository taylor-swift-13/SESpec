import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstMissing {

    //@ requires array != null && array.length > 0;
    //@ requires 0 <= start && start <= end && end < array.length;
    //@ requires (\forall int i; start <= i && i <= end; array[i] >= i); // Array values are greater than or equal to their indices
    //@ ensures \result >= start && \result <= end + 1;
 
 
    public static int findFirstMissing(int[] array, int start, int end) {
        int min = start;
        int max = end;
        int mid;

        //@ maintaining start <= min && min <= max + 1 && max <= end;
 
 
        //@ decreases max - min + 1;
        while (min <= max) {
            mid = (min + max) / 2;
            int current = array[mid];

            if (current == mid) {
                min = mid + 1;
            } else if (current < mid) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return min;
    }
}