import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestMissing {

    //@ requires a != null;
    //@ requires 0 <= leftElement && leftElement <= rightElement + 1;
    //@ requires rightElement < a.length;
    //@ requires (\forall int k; leftElement <= k && k <= rightElement; a[k] >= k);
    //@ ensures leftElement <= \result && \result <= rightElement + 1;
 
 
    public static int smallestMissing(int[] a, int leftElement, int rightElement) {
        int i = leftElement;
        int j = rightElement;
        //@ maintaining leftElement <= i && i <= rightElement + 1;
        //@ maintaining leftElement - 1 <= j && j <= rightElement;
 
 
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
