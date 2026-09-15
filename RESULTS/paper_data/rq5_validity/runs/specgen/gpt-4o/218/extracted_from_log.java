import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class First {

    //@ requires args != null && args.length == n;
    //@ requires (\forall int i; 0 <= i && i < n-1; args[i] <= args[i+1]); // Array must be sorted
    //@ ensures \result == -1 || (0 <= \result && \result < n && args[\result] == Array);
    //@ ensures (\result == -1 ==> (\forall int i; 0 <= i && i < n; args[i] != Array)); // No match found
    //@ ensures (\result != -1 ==> (\result == 0 || args[\result-1] != Array)); // First occurrence
    public static int first(int[] args, int Array, int n) {
        int low = 0;
        int high = n - 1;
        int result = -1;

        //@ maintaining 0 <= low && low <= high + 1 && high < n;
        //@ maintaining (\forall int k; 0 <= k && k < low; args[k] < Array); // All elements before `low` are less than `Array`
        //@ maintaining (\forall int k; high+1 <= k && k < n; args[k] > Array); // All elements after `high` are greater than `Array`
        //@ decreases high - low + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (args[mid] == Array) {
                result = mid;
                high = mid - 1; // Narrow search to find the first occurrence
            } else if (args[mid] < Array) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
}