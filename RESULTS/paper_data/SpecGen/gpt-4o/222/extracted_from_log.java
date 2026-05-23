import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

    //@ requires arr != null && arr.length == n && n >= 0;
 
 
    public static int findOddPair(int[] arr, int n) {
        int result = 0;
        int offset = arr.length;
        //@ maintaining 0 <= index && index <= offset;
 
        //@ maintaining (\forall int i, j; 0 <= i && i < j && j < index; ((arr[i] ^ arr[j]) % 2 == 1 ? 1 : 0) <= result);
        //@ decreases offset - index;
        for (int index = 0; index < offset; index++) {
            //@ maintaining index + 1 <= c && c <= offset;
            //@ maintaining (\forall int i, j; 0 <= i && i < j && j < index; ((arr[i] ^ arr[j]) % 2 == 1 ? 1 : 0) <= result);
            //@ maintaining (\forall int i, j; 0 <= i && i <= j && j <= c && i >= index; ((arr[i] ^ arr[j]) % 2 == 1 ? 1 : 0) < result);  
            //@ decreases offset - c;
            for (int c = index + 1; c < offset; c++) {
                if ((arr[index] ^ arr[c]) % 2 == 1) {
                    result++;
                }
            }
        }
        return result;
    }
}