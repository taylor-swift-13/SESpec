import java.io.*;

class FindExtra {

    //@ requires arr1 != null && arr2 != null;
    //@ requires arr1.length == n && arr2.length == n - 1;
    //@ requires (\forall int i; 0 <= i && i < arr2.length; arr1[i] == arr2[i] || arr1[i] != arr2[i]);
    //@ ensures 0 <= \result && \result < arr1.length;
 
 
    public static int findExtra(int[] arr1, int[] arr2, int n) {
        int left = 0, right = n - 1;

        //@ maintaining 0 <= left && left <= right && right < arr1.length;
        //@ decreases right - left;
        while (left < right) {
            int mid = (left + right) / 2;

            // If elements up to mid are the same, the extra element is in the right half
            if (arr1[mid] == arr2[mid]) {
                left = mid + 1;
            } else {
                // Otherwise, the extra element is in the left half
                right = mid;
            }
        }

        //@ assert left == right;
        return left;
    }
}