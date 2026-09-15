import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

    //@ requires arr != null && arr.length > 0 && n == arr.length;
 
 
    public static int findOddPair(int[] arr, int n) {
        int result = 0;
        int offset = arr.length;
        //@ maintaining 0 <= c && c <= offset;
 
        //@ maintaining (\exists int i, j; 0 - 1 <= i && i < j && j < c; ((arr[i] ^ arr[j]) % 2 == 1 ? 1 : 0) <= result);  
        //@ decreases offset - c;
        for (int c = 0; c < offset; c++) {
            //@ maintaining c + 1 <= index && index <= offset;
            //@ maintaining (\forall int i, j; 0 < i && i < j && j < index && i == c; ((arr[i] ^ arr[j]) % 2 == 1 ? 1 : 0) < result);  
            //@ decreases offset - index;
            for (int index = c + 1; index < offset; index++) {
                if ((arr[c] ^ arr[index]) % 2 == 1) {
                    result++;
                }
            }
        }
        return result;
    }
}