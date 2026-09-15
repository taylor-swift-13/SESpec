import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RightInsertion {

    //@ requires a != null;
    //@ ensures 0 <= \result && \result <= a.length;
    public static int rightInsertion(int[] a, int x) {
        int i = 0;
        int j = a.length - 1;
        /*@ maintaining 0 <= i && i <= a.length;
          @ maintaining -1 <= j && j < a.length;
          @ maintaining i <= j + 1;
          @ decreases j - i + 1;
          @*/
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }
}