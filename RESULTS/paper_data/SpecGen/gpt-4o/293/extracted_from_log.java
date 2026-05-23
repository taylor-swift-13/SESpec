import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

    //@ requires seed >= 0;
 
 
    //@ ensures seed > 2 ==> (\exists int[] arr; arr.length == seed + 1 && arr[0] == 0 && arr[1] == 1 && (\exists int i; 2 < i && i < seed; arr[i] == (2 * arr[i - 1] + arr[i - 2]) % 1000000000) || \result == arr[seed]);  
    public static int getPell(int seed) {
        int[] arr = new int[seed + 1];
        //@ assume arr.length > 0;
        arr[0] = 0;
        //@ assume arr.length > 1;
        arr[1] = 1;
        //@ maintaining 2 <= p && p <= seed + 1;
 
        //@ decreases seed - p + 1;
        for (int p = 2; p <= seed; p++) {
            //@ assume p - 1 < arr.length && p - 2 < arr.length && p < arr.length;
            arr[p] = (2 * arr[p - 1]
                    + arr[p - 2]) % 1000000000;
        }
        return arr[seed];
    }
}