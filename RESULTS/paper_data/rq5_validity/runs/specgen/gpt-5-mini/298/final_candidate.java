import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestMissing {

    //@ requires a != null;
    //@ requires 0 <= leftElement && leftElement <= rightElement && rightElement < a.length;
    //@ // The set of indices where a[k]==k is a prefix of [leftElement..rightElement]
    //@ requires (\forall int k; leftElement <= k && k <= rightElement && a[k] == k
    //@            ==> (\forall int m; leftElement <= m && m <= k; a[m] == m));
    //@ ensures leftElement <= \result && \result <= rightElement + 1;
    //@ ensures (\forall int k; leftElement <= k && k < \result; a[k] == k);
    //@ ensures (\forall int k; \result <= k && k <= rightElement; a[k] != k);
    public static int smallestMissing(int[] a, int leftElement, int rightElement) {
        int i = leftElement;
        int j = rightElement;
        //@ maintaining leftElement <= i && i <= rightElement + 1;
        //@ maintaining leftElement - 1 <= j && j <= rightElement;
        //@ maintaining i <= j + 1;
        //@ maintaining (\forall int k; leftElement <= k && k < i; a[k] == k);
        //@ maintaining (\forall int k; j < k && k <= rightElement; a[k] != k);
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