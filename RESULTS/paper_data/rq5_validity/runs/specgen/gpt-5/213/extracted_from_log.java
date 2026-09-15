import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

    //@ requires arr != null && ranges != null;
    //@ requires 0 <= rotations && rotations <= ranges.length;
    //@ requires 0 <= index && index < arr.length;
    //@ requires (\forall int t; 0 <= t && t < rotations;
    //@             ranges[t] != null && ranges[t].length >= 2
    //@             && 0 <= ranges[t][0] && ranges[t][0] <= ranges[t][1] && ranges[t][1] < arr.length);
    //@ ensures 0 <= index && index < arr.length;
    //@ ensures \result == arr[index];
    //@ ensures (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
    //@ ensures (\forall int t; 0 <= t && t < ranges.length;
    //@             ranges[t] != null ==> (\forall int q; 0 <= q && q < ranges[t].length; ranges[t][q] == \old(ranges[t][q])));
    public static int findElement(int[] arr, int[][] ranges, int rotations, int index) {
        //@ maintaining -1 <= i && i < rotations;
        //@ maintaining 0 <= index && index < arr.length;
        //@ maintaining (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
        //@ maintaining (\forall int t; 0 <= t && t < rotations; ranges[t] != null && ranges[t].length >= 2);
        //@ decreases i + 1;
        for (int i = rotations - 1; i >= 0; i--) {
            int left = ranges[i][0];
            int right = ranges[i][1];
            if (left <= index && right >= index) {
                if (index == left) {
                    index = right;
                } else {
                    index = index - 1;
                }
            }
        }
        return arr[index];
    }
}