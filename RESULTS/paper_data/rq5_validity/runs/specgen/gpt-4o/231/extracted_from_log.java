import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

    //@ requires p != null && p.length >= 0;
    //@ ensures \result >= 0;
 
    public static int countPairs(int[] p, int array) {
        int count = 0;
        int total = p.length;

        //@ maintaining 0 <= index && index - 1 <= total - 1;  
        //@ maintaining count >= 0;
        //@ maintaining (\forall int i, j; 0 < i && i < j && j < index; (p[i] != p[j] ? 1 : 0) - 1 <= count);  
        //@ decreases total - 1 - index;
        for (int index = 0; index < total - 1; index++) {
            //@ maintaining index + 1 <= c && c <= total;
            //@ maintaining count >= 0;
            //@ maintaining (\forall int i, j; 0 < i && i < j && j < c; (p[i] != p[j] ? 1 : 0) - 1 <= count);  
            //@ decreases total - c;
            for (int c = index + 1; c < total; c++) {
                if (p[index] != p[c]) {
                    count++;
                }
            }
        }
        return count;
    }
}