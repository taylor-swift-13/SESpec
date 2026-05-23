import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindEvenPair {

    //@ requires arr != null;
    //@ requires n == arr.length;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int i; 0 <= i && i < arr.length; (\sum int c; i + 1 <= c && c < arr.length; (((arr[i] ^ arr[c]) & 1) == 0 ? 1 : 0)));
    public static int findEvenPair(int[] arr, int n) {
        if (arr == null) {
            return -1;
        }
        if (arr.length == 1) {
            return 0;
        }

        int evenPairCount = 0;
        //@ maintaining 0 <= i && i <= arr.length;
        //@ maintaining evenPairCount >= 0;
        //@ maintaining evenPairCount == (\sum int x; 0 <= x && x < i; (\sum int y; x - 1 <= y && y <= arr.length; (((arr[x] ^ arr[y]) & 1) == 0 ? 1 : 0)));  
        //@ decreases arr.length - i;
        for (int i = 0; i < arr.length; i++) {
            //@ maintaining i + 1 <= c && c <= arr.length;
            //@ maintaining evenPairCount >= 0;
            //@ maintaining evenPairCount == (\sum int x; 0 <= x && x < i; (\sum int y; x + 1 <= y && y < arr.length; (((arr[x] ^ arr[y]) & 1) == 0 ? 1 : 0))) + (\sum int y; i + 1 <= y && y < c; (((arr[i] ^ arr[y]) & 1) == 0 ? 1 : 0));
            //@ decreases arr.length - c;
            for (int c = i + 1; c < arr.length; c++) {
                int even = arr[i];
                int odd = arr[c];
                int z = even ^ odd;
                if ((z & 1) == 0) {
                    evenPairCount++;
                }
            }
        }
        return evenPairCount;
    }
}