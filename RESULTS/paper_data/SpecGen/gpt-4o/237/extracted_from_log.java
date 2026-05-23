import java.io.*;

   class First {

       //@ requires arr != null;
       //@ requires n > 0 && n <= arr.length;
       //@ requires (\forall int i; 0 <= i && i < n-1; arr[i] <= arr[i+1]); // Array is sorted
       //@ ensures \result == -1 || (0 <= \result && \result < n && arr[\result] == x);
       public static int first(int[] arr, int x, int n) {
           int low = 0;
           int high = n - 1;
           int result = -1;

           //@ maintaining 0 <= low && low <= high + 1 && high < n;
           //@ maintaining result == -1 || (0 <= result && result < n && arr[result] == x);
           //@ decreases high - low + 1;
           while (low <= high) {
               int mid = low + (high - low) / 2; // Avoid potential overflow
               if (arr[mid] == x) {
                   result = mid;
                   high = mid - 1; // Continue searching in the left half for the first occurrence
               } else if (arr[mid] < x) {
                   low = mid + 1;
               } else {
                   high = mid - 1;
               }
           }
           return result;
       }
   }