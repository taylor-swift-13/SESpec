import java.io.*;

class First {

    //@ requires args != null; // The array must not be null.
    //@ requires (\forall int i; 0 <= i && i < args.length - 1; args[i] <= args[i + 1]); // The array must be sorted in non-decreasing order.
    //@ ensures \result == -1 || (0 <= \result && \result < args.length && args[\result] == array); // Result is either -1 or a valid index where the value is found.
    //@ ensures \result >= 0 ==> (\forall int i; 0 <= i && i < \result; args[i] != array); // If result is valid, it is the first occurrence of the value.
    public static int first(int[] args, int array) {
        int low = 0;
        int high = args.length - 1;
        int result = -1;

        //@ maintaining 0 <= low && low <= high + 1 && high < args.length; // Loop bounds are valid.
        //@ maintaining result == -1 || (0 <= result && result < args.length && args[result] == array); // Result is either -1 or a valid index where the value is found.
        //@ maintaining (\forall int i; 0 <= i && i < low; args[i] != array); // All elements before low are not equal to the value.
        //@ maintaining (\forall int i; high + 1 <= i && i < args.length; args[i] != array); // All elements after high are not equal to the value.
        //@ decreases high - low + 1; // The loop progresses by reducing the search space.
        while (low <= high) {
            int mid = (low + high) / 2;
            if (args[mid] == array) {
                result = mid;
                high = mid - 1; // Continue searching in the left half for the first occurrence.
            } else if (args[mid] < array) {
                low = mid + 1; // Search in the right half.
            } else {
                high = mid - 1; // Search in the left half.
            }
        }
        return result;
    }
}