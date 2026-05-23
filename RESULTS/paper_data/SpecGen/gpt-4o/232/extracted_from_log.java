import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

    //@ requires pairs != null && pairs.length > 0;
    //@ ensures \result >= 0;
 
    public static int countPairs(int[] pairs, int array) {
        int count = 0;
        int total = pairs.length;

        //@ maintaining 0 <= index && index <= total - 1;
        //@ maintaining count >= 0;
        //@ maintaining (\forall int i, j; 0 < i && i < index && index < j && j < total; (pairs[i] != pairs[j] ? 1 : 0) - 1 <= count);  
        //@ decreases total - 1 - index;
        for (int index = 0; index < total - 1; index++) {

            //@ maintaining index + 1 <= c && c <= total;
            //@ maintaining count >= 0;
            //@ maintaining (\forall int i, j; 0 < i && i < index && index < j && j < c; (pairs[i] != pairs[j] ? 1 : 0) - 1 <= count);  
            //@ decreases total - c;
            for (int c = index + 1; c < total; c++) {
                if (pairs[index] != pairs[c]) {
                    count++;
                }
            }
        }
        return count;
    }
}