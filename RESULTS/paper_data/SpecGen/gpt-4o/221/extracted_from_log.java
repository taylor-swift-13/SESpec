import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindOddPair {

    //@ requires arr != null && arr.length > 0;
    //@ requires n == arr.length;
 
 
    public static int findOddPair(int[] arr, int n) {
        int found = 0;
        int offset = arr.length;

        //@ maintaining 0 <= c && c <= offset;
 
        //@ decreases offset - c;
        for (int c = 0; c < offset; c++) {
            //@ maintaining c + 1 <= index && index <= offset;
 
            //@ decreases offset - index;
            for (int index = c + 1; index < offset; index++) {
                if ((arr[c] ^ arr[index]) % 2 == 1) {
                    found++;
                }
            }
        }
        return found;
    }
}