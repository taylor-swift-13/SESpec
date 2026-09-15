import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

    //@ requires arr != null && ranges != null;
    //@ requires array > 0 && array <= ranges.length;
    //@ requires count >= 0 && count < arr.length;
    //@ requires (\forall int r; 0 <= r && r < ranges.length; ranges[r].length == 2);
 
 
    public static int findElement(int[] arr, int[][] ranges, int array, int count) {
        //@ maintaining array - 1 >= r && r >= -1;
        //@ maintaining (\forall int k; r + 1 <= k && k < array; ranges[k][0] <= count && ranges[k][1] >= count ==> 
        //@                (count == ranges[k][0] ==> count == ranges[k][1]) || (count != ranges[k][0] ==> count == count - 1));
        //@ decreases r + 1;
        for (int r = array - 1; r >= 0; r--) {
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
        //@ assume count >= 0 && count < arr.length;
        return arr[count];
    }
}