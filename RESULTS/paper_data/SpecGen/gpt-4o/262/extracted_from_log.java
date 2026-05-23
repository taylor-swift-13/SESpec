import java.io.*;

class LeftInsertion {

    //@ requires a != null;
    //@ requires (\forall int i; 0 <= i && i < a.length - 1; a[i] <= a[i + 1]);
    //@ ensures 0 <= \result && \result <= a.length;
    //@ ensures (\result == a.length || a[\result] >= x);
    //@ ensures (\result == 0 || a[\result - 1] < x);
    public static int leftInsertion(int[] a, int x) {
        int left = 0;
        int right = a.length;
        //@ maintaining 0 <= left && left <= right && right <= a.length;
        //@ maintaining (\forall int i; 0 <= i && i < left; a[i] < x);
        //@ maintaining (\forall int i; right <= i && i < a.length; a[i] >= x);
        //@ decreases right - left;
        while (left < right) {
            int mid = left + (right - left) / 2; // Avoid potential overflow
            if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}