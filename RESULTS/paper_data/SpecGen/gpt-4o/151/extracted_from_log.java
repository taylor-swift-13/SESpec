import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

    //@ requires number > 0 && p > 0;
    //@ ensures \result == 0 || (\exists int count; count == p && (\exists int i; 1 <= i && i <= number; \result == i && ((\result % 2 != 0 && count == (\num_of int j; 1 <= j && j <= number; j % 2 != 0)) || (\result % 2 == 0 && count == (\num_of int j; 1 <= j && j <= number; j % 2 == 0)))));
    public static int getNumber(int number, int p) {
        int result[] = new int[number];
        int b[] = new int[number];
        int c, ii = 0;

        //@ maintaining 0 <= c && c <= number;
        //@ maintaining (\forall int i; 0 <= i && i < c; result[i] == i + 1);
        //@ decreases number - c;
        for (c = 0; c < number; c++) {
            result[c] = c + 1;
        }

        //@ maintaining 0 <= c && c <= number;
        //@ maintaining 0 <= ii && ii < p;  
        //@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
        //@ maintaining (\forall int i; 0 < i && i < c; result[i] % 2 != 0 ==> ii > 1);  
        //@ decreases number - c;
        for (c = 0; c < number; c++) {
            b[c] = result[c];
            if (result[c] % 2 != 0) {
                ii++;
                if (ii == p) {
                    return result[c];
                }
            }
        }

        //@ maintaining 0 <= c && c <= number;
 
        //@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
        //@ maintaining (\exists int i; 0 <= i && i <= c; result[i] % 2 == 0 ==> ii >= 1);  
        //@ decreases number - c;
        for (c = 0; c < number; c++) {
            b[c] = result[c];
            if (result[c] % 2 == 0) {
                ii++;
                if (ii == p) {
                    return result[c];
                }
            }
        }

        return 0;
    }
}