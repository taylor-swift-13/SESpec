import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

    //@ requires value > 0 && p > 0;
    //@ ensures \result == 0 || (\exists int count; 0 <= count && count < value; (\forall int i; 0 <= i && i < count; (i + 1) % 2 != 0 || (i + 1) % 2 == 0) && (count + 1) == \result);
    public static int getNumber(int value, int p) {
        int result[] = new int[value];
        int b[] = new int[value];
        int c, j = 0;

        //@ maintaining 0 <= c && c <= value;
        //@ maintaining (\forall int i; 0 <= i && i < c; result[i] == i + 1);
        //@ decreases value - c;
        for (c = 0; c < value; c++) {
            result[c] = c + 1;
        }

        //@ maintaining 0 <= c && c <= value;
        //@ maintaining 0 <= j && j < p;  
        //@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
        //@ maintaining (\forall int i; 0 < i && i < c; (result[i] % 2 != 0) ==> j + 1 >= 1);  
        //@ decreases value - c;
        for (c = 0; c < value; c++) {
            b[c] = result[c];
            if (result[c] % 2 != 0) {
                j++;
                if (j == p) {
                    return result[c];
                }
            }
        }

        //@ maintaining 0 <= c && c <= value;
 
        //@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
 
        //@ decreases value - c;
        for (c = 0; c < value; c++) {
            b[c] = result[c];
            if (result[c] % 2 == 0) {
                j++;
                if (j == p) {
                    return result[c];
                }
            }
        }

        return 0;
    }
}