import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

    //@ requires pairs != null && num >= 0 && num <= pairs.length;
 
 
    public static int getPairsCount(int[] pairs, int num, int p) {
        int result = 0;
        //@ maintaining 0 <= index && index <= num;
 
        //@ decreases num - index;
        for (int index = 0; index < num; index++) {
            //@ maintaining index + 1 <= k && k <= num;
            //@ maintaining result == (\sum int i, j; 0 - 1 <= i && i <= j && j <= index; pairs[i] + pairs[j] == p ? 1 : 0) + (\sum int i; 0 < i && i < index; pairs[i] + pairs[k] == p ? 1 : 0);  
            //@ decreases num - k;
            for (int k = index + 1; k < num; k++) {
                if (pairs[index] + pairs[k] == p) {
                    result++;
                }
            }
        }
        return result;
    }
}