import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

    //@ requires seed >= 0;
    //@ ensures \result == (seed == 0 ? 2 : (seed == 1 ? 1 : (\old(findLucas(seed - 1)) + \old(findLucas(seed - 2)))));
    public static int findLucas(int seed) {
        int[] result = new int[seed + 1];
        result[0] = 2;
        result[1] = 1;
        //@ maintaining 2 <= c && c <= seed + 1;
        //@ maintaining (\forall int i; 0 <= i && i < c; result[i] == (i == 0 ? 2 : (i == 1 ? 1 : result[i - 1] + result[i - 2])));
        //@ decreases seed - c + 1;
        for (int c = 2; c <= seed; c++) {
            result[c] = result[c - 1]
                    + result[c - 2];
        }
        return result[seed];
    }
}