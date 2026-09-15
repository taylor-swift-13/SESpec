import java.io.*;

class FindPeak {

    /*@ spec_public @*/
    public static int findPeak(int[] data, int array) {
        //@ requires data != null && array > 0 && data.length == array;
 
 
        int low = 0, high = array - 1;

 
        //@ decreases high - low;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (data[mid] < data[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}