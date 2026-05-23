import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

/*@ spec_public @*/ class SmallestMissing {

    //@ requires a != null;
    //@ requires 0 <= leftElement && leftElement <= rightElement && rightElement < a.length;
    //@ ensures leftElement <= \result && \result <= rightElement + 1;
    //@ ensures \result > leftElement ==> a[\result - 1] == \result - 1;
    //@ ensures \result <= rightElement ==> a[\result] != \result;
    //@ assignable \nothing;
    /*@ spec_public @*/ public static int smallestMissing(int[] a, int leftElement, int rightElement) {
        int i = leftElement;
        int j = rightElement;
        //@ maintaining leftElement <= i && i <= j + 1 && j <= rightElement;
        //@ maintaining i > leftElement ==> a[i-1] == i-1;
        //@ maintaining j < rightElement ==> a[j+1] != j+1;
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