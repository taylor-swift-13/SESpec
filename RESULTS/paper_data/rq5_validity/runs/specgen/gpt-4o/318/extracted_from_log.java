import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

    //@ requires num > 0;
    //@ ensures \result >= 0;
 
    public static int countFac(int num) {
        int result = 0;
        if (num == 1)
            return 1;
        //@ maintaining 2 <= c && c - 1 <= num / c + 1;  
        //@ maintaining result >= 0;
 
        //@ decreases num / c - c + 1;
        for (int c = 2; c <= num / c; c++) {
            if (num % c == 0) {
                result++;
                if (num / c == c) {
                    break;
                }
            }
        }
        return result;
    }
}