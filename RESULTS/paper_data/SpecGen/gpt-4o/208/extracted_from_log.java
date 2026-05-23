import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

    //@ requires arr != null && ranges != null && num >= 0 && count >= 0;
    //@ requires ranges.length == num && (\forall int i; 0 <= i && i < num; ranges[i].length == 2);
    //@ requires (\forall int i; 0 <= i && i < num; 0 <= ranges[i][0] && ranges[i][0] <= ranges[i][1] && ranges[i][1] < arr.length);
    //@ ensures 0 <= count && count < arr.length;
    //@ ensures \result == arr[count];
    public static int findElement(int[] arr, int[][] ranges, int num, int count) {
        //@ maintaining num - 1 >= r && r >= -1;
 
        //@ maintaining (\forall int i; r + 1 <= i && i < num; !(ranges[i][0] <= count && ranges[i][1] >= count));
        //@ decreases r;
        for (int r = num - 1; r >= 0; r--) {
            int j = ranges[r][0];
            int top = ranges[r][1];
            if (j <= count && top >= count) {
                if (count == j) {
                    count = top;
                } else {
                    count = count - 1;
                }
            }
        }
        return arr[count];
    }
}