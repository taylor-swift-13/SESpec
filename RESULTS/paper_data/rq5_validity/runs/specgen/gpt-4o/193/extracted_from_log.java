import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountWays {

    //@ requires count >= 0;
    //@ ensures \result >= 0;
 
    public static int countWays(int count) {
        int[] arr = new int[count + 1];
        int[] C = new int[count + 1];
        //@ assume 0 < arr.length;
        arr[0] = 1;
        //@ assume 1 < arr.length;
        arr[1] = 0;
        //@ assume 0 < C.length;
        C[0] = 0;
        //@ assume 1 < C.length;
        C[1] = 1;
        //@ maintaining 2 <= w && w <= count + 1;
        //@ maintaining (\forall int i; 0 <= i && i < w; arr[i] >= 0 && C[i] >= 0);
        //@ decreases count - w + 1;
        for (int w = 2; w <= count; w++) {
            //@ assume w - 2 >= 0 && w - 2 < arr.length;
            //@ assume w - 1 >= 0 && w - 1 < C.length;
            arr[w] = arr[w - 2]
                    + 2 * C[w - 1];
            //@ assume w - 1 >= 0 && w - 1 < arr.length;
            //@ assume w - 2 >= 0 && w - 2 < C.length;
            C[w] = arr[w - 1] + C[w - 2];
        }
        return arr[count];
    }
}