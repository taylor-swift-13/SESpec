import java.io.*;
import java.lang.*;
import java.util.*;

class LeftInsertion {

    //@ requires args != null && args.length >= 0;
    //@ requires \forall int i; 0 <= i && i < args.length - 1; args[i] <= args[i + 1];
    //@ ensures 0 <= \result && \result <= args.length;
    //@ ensures (\forall int i; 0 <= i && i < \result; args[i] < array);
    //@ ensures (\forall int i; \result <= i && i < args.length; args[i] >= array);
    public static int leftInsertion(int[] args, int array) {
        int low = 0;
        int high = args.length;

        //@ maintaining 0 <= low && low <= high && high <= args.length;
        //@ maintaining (\forall int i; 0 <= i && i < low; args[i] < array);
        //@ maintaining (\forall int i; high <= i && i < args.length; args[i] >= array);
        //@ decreases high - low;
        while (low < high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow
            if (args[mid] < array) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}