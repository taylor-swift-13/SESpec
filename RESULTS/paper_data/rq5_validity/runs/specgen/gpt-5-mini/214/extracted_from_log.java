import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

    //@ requires num >= 0;
 
 
    //@ ensures (\exists int[] cat; cat != null && cat.length == num + 1 ||  
    //@            cat[0] == 1 &&
    //@            (\forall int i; 1 <= i && i <= num;
    //@                 cat[i] == (\sum int j; 0 <= j && j < i; cat[j] * cat[i - j - 1])
    //@            ) &&
    //@            \result == cat[num]);
    public static int catalanNumber(int num) {
        int[] catalan = new int[num + 1];
        catalan[0] = 1;
        //@ maintaining catalan != null && catalan.length == num + 1;
 
        //@ maintaining (\forall int k; 0 < k && k < 1; catalan[k] == 1);  
        //@ maintaining 0 <= i && i <= num+1;
        //@ decreases num - i + 1;
        for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            //@ maintaining 0 <= j && j <= i;
            //@ maintaining catalan.length == num + 1;
 
            //@ maintaining (\exists int t; 0 <= t && t <= i || t <= j; catalan[t] >= 0);  
 
            //@ decreases i - j;
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[num];
    }
}