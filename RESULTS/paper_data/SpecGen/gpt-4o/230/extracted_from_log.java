import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountPairs {

    //@ requires pairs != null && pairs.length > 0;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int i, j; 0 <= i && i < j && j < pairs.length; pairs[i] != pairs[j] ? 1 : 0);
    public static int countPairs(int[] pairs, int array) {
        int count = 0;
        int total = pairs.length;
        //@ maintaining 0 <= index && index <= total - 1;
        //@ maintaining count >= 0;
        //@ maintaining (\forall int i, j; 0 <= i && i < j && j < total; pairs[i] != pairs[j] ==> count > (\sum int x, y; 0 <= x && x < y && y <= index; pairs[x] != pairs[y] ? 1 : 0));  
        //@ decreases total - index;
        for (int index = 0; index < total - 1; index++) {
            //@ maintaining index + 1 <= k && k <= total;
            //@ maintaining count >= 0;
            //@ maintaining (\forall int i, j; 0 <= i && i < j && j < total; pairs[i] != pairs[j] ==> count >= (\sum int x, y; 0 <= x && x < y && y < index; pairs[x] != pairs[y] ? 1 : 0));
            //@ decreases total - k;
            for (int k = index + 1; k < total; k++) {
                if (pairs[index] != pairs[k]) {
                    count++;
                }
            }
        }
        return count;
    }
}