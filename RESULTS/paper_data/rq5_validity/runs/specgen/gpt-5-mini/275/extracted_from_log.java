import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class PairOrSum {

    /*@ 
      @ requires arr != null;
      @ requires n == arr.length;
 
      @*/
    public static int pairOrSum(int[] arr, int n) {
        int sum = 0;
        /*@ 
          @ maintaining 0 <= i && i <= arr.length;
 
          @ decreases arr.length - i;
          @*/
        for (int i = 0; i < arr.length; i++) {
            /*@ 
 
 
              @                   + (\sum int q; i+1 <= q && q < j; arr[i] ^ arr[q]);
              @ decreases arr.length - j;
              @*/
            for (int j = i + 1; j < arr.length; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
    }
}