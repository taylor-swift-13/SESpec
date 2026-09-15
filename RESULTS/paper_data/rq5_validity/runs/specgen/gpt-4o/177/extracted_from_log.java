import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

    //@ requires arr != null;
    //@ requires arr.length >= 0;
    //@ requires \forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1]; // Array must be sorted
    //@ ensures (\result == -1) <==> (\forall int i; 0 <= i && i < arr.length; arr[i] != target); // If not found, return -1
    //@ ensures \result >= 0 ==> (arr[\result] == target && (\result == arr.length - 1 || arr[\result + 1] != target)); // Ensure last occurrence
    public static int findLastOccurrence(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;
        int result = -1;

        //@ maintaining 0 <= low && low <= high + 1 && high < arr.length;
        //@ maintaining result == -1 || (result >= 0 && arr[result] == target);
        //@ decreases high - low + 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                result = mid; // Update result to the current index
                low = mid + 1; // Continue searching in the right half
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
}