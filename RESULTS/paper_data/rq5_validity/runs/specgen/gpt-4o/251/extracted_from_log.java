import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstMissing {

    //@ requires args.length > 0;
    //@ requires 0 <= start && start <= stop && stop < args.length;
    //@ requires (\forall int i; 0 <= i && i < args.length; args[i] >= 0);
 
 
    public static int findFirstMissing(int[] args, int start, int stop) {
        int found = start;
        int total = stop;
        int mid;

        //@ maintaining start <= found && found <= total + 1 && total <= stop;
 
 
        //@ decreases total - found + 1;
        while (found <= total) {
            mid = (found + total) / 2;
            int i = args[mid];

            if (i == mid) {
                found = mid + 1;
            } else if (i < mid) {
                found = mid + 1;
            } else {
                total = mid - 1;
            }
        }
        return found;
    }
}