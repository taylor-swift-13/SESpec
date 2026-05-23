import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

    //@ requires pairs != null && pairs.length >= num && num > 0;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int i; 0 <= i && i < num; (\sum int k; i + 1 <= k && k < num; (pairs[i] + pairs[k] == p ? 1 : 0)));
    public static int getPairsCount(int[] pairs, int num, int p) {
        int ret = 0;
        //@ maintaining 0 <= index && index <= num;
        //@ maintaining ret == (\sum int i; 0 - 1 <= i && i < index; (\sum int k; i - 1 - 1 <= k && k <= num; (pairs[i] - pairs[k] == p ? 1 : 0)));  
        //@ decreases num - index;
        for (int index = 0; index < num; index++) {
            //@ maintaining index + 1 <= j && j <= num;
            //@ maintaining ret == (\sum int i; 0 <= i && i < index; (\sum int k; i + 1 <= k && k < num; (pairs[i] + pairs[k] == p ? 1 : 0)))
            //@                + (\sum int k; index + 1 <= k && k < num; (pairs[index] + pairs[k] == p ? 1 : 0));
            //@ decreases num - j;
            for (int j = index + 1; j < num; j++) {
                if (pairs[index] + pairs[j] == p) {
                    ret++;
                }
            }
        }
        return ret;
    }
}