import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestMissing {

    //@ requires a != null && a.length > 0;
    //@ requires (\forall int i; 0 <= i && i < a.length; a[i] >= 0);
    //@ requires 0 <= leftElement && leftElement <= rightElement && rightElement < a.length;
    //@ ensures \result >= leftElement && \result <= rightElement + 1;
 
 
    public static int smallestMissing(int[] a, int leftElement, int rightElement) {
        int i = leftElement;
        int j = rightElement;
        //@ maintaining leftElement <= i && i <= j + 1 && j >= leftElement - 1 && j <= rightElement;
 
 
        //@ decreases j - i + 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }
}