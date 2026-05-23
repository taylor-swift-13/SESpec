import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

    /*@ public normal_behavior
      @ requires num >= 0;
 
 
 
      @*/
    public static int catalanNumber(int num) {
        int[] catalan = new int[num + 1];
        catalan[0] = 1;
        //@ maintaining 1 <= i && i <= num + 1;
 
        //@ decreases num - i + 1;
        for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            //@ maintaining 0 <= j && j <= i;
 
            //@ decreases i - j;
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[num];
    }
}