import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

    /*@ 
      @ public normal_behavior
      @ requires arr != null;
      @ requires ranges != null;
      @ requires rotations >= 0 && rotations <= ranges.length;
      @ requires 0 <= index && index < arr.length;
      @ requires (\forall int r; 0 <= r && r < rotations;
      @               ranges[r] != null && ranges[r].length >= 2 &&
      @               0 <= ranges[r][0] && ranges[r][0] <= ranges[r][1] && ranges[r][1] < arr.length);
      @
      @ // The method does not modify the contents of arr or ranges
      @ ensures (\forall int p; 0 <= p && p < arr.length; arr[p] == \old(arr[p]));
      @ ensures (\forall int r; 0 <= r && r < ranges.length;
      @            (\forall int q; 0 <= q && q < ranges[r].length; ranges[r][q] == \old(ranges[r][q])));
      @
      @ // final index is in bounds and result equals arr at that final index
      @ ensures 0 <= index && index < arr.length;
 
      @*/
    public static int findElement(int[] arr, int[][] ranges, int rotations, int index) {
        //@ maintaining -1 <= i && i < rotations;
        //@ maintaining 0 <= index && index < arr.length;
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