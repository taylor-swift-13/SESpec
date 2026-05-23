import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstMissing {

    //@ requires args != null && args.length > 0;
    //@ requires 0 <= start && start <= stop && stop < args.length;
    //@ requires (\forall int i; start <= i && i <= stop; args[i] >= start && args[i] <= stop);
 
 
 
    public static int findFirstMissing(int[] args, int start, int stop) {
        int result = start;
        int total = stop;
        int mid;

        //@ maintaining start <= result && result <= total + 1;
        //@ maintaining start - 1 <= total && total < args.length;  
 
 
        //@ decreases total - result + 1;
        while (result <= total) {
            mid = (result + total) / 2;
            int i = args[mid];

            if (i == mid) {
                result = mid + 1;
            } else if (i < mid) {
                result = mid + 1;
            } else {
                total = mid - 1;
            }
        }
        return result;
    }
}