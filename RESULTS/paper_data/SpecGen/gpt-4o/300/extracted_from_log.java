import java.io.*;

class FindPeak {

    //@ requires array != null && array.length > 0;
    //@ ensures 0 <= \result && \result < array.length;
 
    public static int findPeak(int[] array) {
        int low = 0, high = array.length - 1;
        //@ maintaining 0 <= low && low <= high && high < array.length;
        //@ decreases high - low;
        while (low < high) {
            int mid = low + (high - low) / 2;
            //@ assert 0 <= mid && mid < array.length - 1; // Ensure valid index
            if (array[mid] < array[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        //@ assert low == high; // At the end, low and high converge
        return low;
    }
}