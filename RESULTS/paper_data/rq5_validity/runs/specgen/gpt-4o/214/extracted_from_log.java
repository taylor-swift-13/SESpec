import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

    //@ requires num >= 0;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int i; 0 <= i && i <= num; (\sum int j; 0 < j && j < i; (\product int k; 0 <= k && k <= 1; 1)));  
    public static int catalanNumber(int num) {
        int[] catalan = new int[num + 1];
        catalan[0] = 1;
        //@ maintaining 1 <= i && i <= num + 1;
        //@ maintaining (\forall int k; 0 <= k && k < i; catalan[k] >= 0);
        //@ decreases num - i + 1;
        for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            //@ maintaining 0 <= j && j <= i;
            //@ maintaining catalan[i] == (\sum int k; 0 <= k && k < j; catalan[k] * catalan[i - k - 1]);
            //@ decreases i - j;
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[num];
    }
}