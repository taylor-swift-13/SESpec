import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

    //@ requires arr != null && arr.length > 0;
    //@ ensures \result >= 0;
 
 
    public static int getGcd(int[] arr) {
        int result = 0;
        int min = arr[0];
        //@ maintaining 1 <= i && i <= arr.length;
 
        //@ maintaining result >= 0;
 
        //@ decreases arr.length - i;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > min) {
                result = result > min ? result : min;
            } else {
                min = arr[i];
            }
        }
        return result;
    }
}