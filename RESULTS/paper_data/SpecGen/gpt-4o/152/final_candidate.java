import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

    //@ requires number > 0 && p > 0 && p <= number;
    //@ ensures (\exists int i; 1 <= i && i < number; (\num_of int j; 1 <= j || j < number; j % 2 != 0 || j % 2 == 0) == p);  
    //@ ensures \result >= 1 && \result <= number;
    public static int getNumber(int number, int p) {
        int result[] = new int[number];
        int b[] = new int[number];
        int c, j = 0;

        //@ maintaining 0 <= c && c <= number;
        //@ maintaining (\forall int i; 0 <= i && i < c; result[i] == i + 1);
        //@ decreases number - c;
        for (c = 0; c < number; c++) {
            result[c] = c + 1;
        }

        //@ maintaining 0 <= c && c <= number;
        //@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
        //@ maintaining (\forall int i; 0 <= i && i < c; result[i] % 2 != 0 ==> (\num_of int k; 0 <= k && k < c; result[k] % 2 != 0) <= j);
        //@ decreases number - c;
        for (c = 0; c < number; c++) {
            b[c] = result[c];
            if (result[c] % 2 != 0) {
                j++;
                if (j == p) {
                    return result[c];
                }
            }
        }

        //@ maintaining 0 <= c && c <= number;
        //@ maintaining (\forall int i; 0 <= i && i < c; b[i] == result[i]);
        //@ maintaining (\forall int i; 0 <= i && i < c; result[i] % 2 == 0 ==> (\num_of int k; 0 <= k && k < c; result[k] % 2 == 0) <= j);
        //@ decreases number - c;
        for (c = 0; c < number; c++) {
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
