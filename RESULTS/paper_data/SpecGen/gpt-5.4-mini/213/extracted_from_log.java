import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

    //@ requires arr != null && ranges != null;
    //@ requires rotations >= 0;
    //@ requires 0 <= index && index < arr.length;
    //@ requires (\forall int i; 0 <= i && i < rotations; ranges[i] != null && ranges[i].length >= 2);
    //@ requires (\forall int i; 0 <= i && i < rotations; 0 <= ranges[i][0] && ranges[i][0] <= ranges[i][1] && ranges[i][1] < arr.length);
 
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