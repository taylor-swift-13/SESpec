import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

    //@ requires arr != null && ranges != null;
    //@ requires array >= 0 && array <= ranges.length;
    //@ requires width >= 0 && width < arr.length;
    //@ requires (\forall int i; 0 <= i && i < ranges.length; ranges[i].length == 2);
 
    public static int findElement(int[] arr, int[][] ranges, int array, int width) {
        //@ maintaining array - 1 >= r && r >= -1;
        //@ maintaining width > 0 && width <= arr.length;  
        //@ maintaining (\forall int i; r + 1 <= i && i < array; 
        //@     (ranges[i][0] <= width && ranges[i][1] >= width) ==> 
        //@     (width == ranges[i][0] || width == ranges[i][1] || width < ranges[i][1]));
        //@ decreases r + 1;
        for (int r = array - 1; r >= 0; r--) {
            int j = ranges[r][0];
            int top = ranges[r][1];
            if (j <= width && top >= width) {
                if (width == j) {
                    width = top;
                } else {
                    width = width - 1;
                }
            }
        }
        return arr[width];
    }
}