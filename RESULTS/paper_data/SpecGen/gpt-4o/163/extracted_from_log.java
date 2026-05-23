import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

    //@ requires arr != null;
    //@ requires n == arr.length;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int i, j; 0 <= i && i < j && j < arr.length; (((arr[i] ^ arr[j]) & 1) == 0 ? 1 : 0));
    public static int findEvenPair(int[] arr, int n) {
        if (arr == null) {
            return -1;
        }
        if (arr.length == 1) {
            return 0;
        }

        int evenPairCount = 0;
        //@ maintaining 0 <= i && i <= arr.length;
 
        //@ decreases arr.length - i;
        for (int i = 0; i < arr.length; i++) {
            //@ maintaining i + 1 <= c && c <= arr.length;
            //@ maintaining evenPairCount == (\sum int x, y; 0 <= x && x <= y && y < i || (x == i && i + 1 < y && y < c); (((arr[x] ^ arr[y]) & 1) == 0 ? 1 : 0));  
            //@ decreases arr.length - c;
            for (int c = i + 1; c < arr.length; c++) {
                int odd = arr[i];
                int b = arr[c];
                int even = odd ^ b;
                if ((even & 1) == 0) {
                    evenPairCount++;
                }
            }
        }
        return evenPairCount;
    }
}