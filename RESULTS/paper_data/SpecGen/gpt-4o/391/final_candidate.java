import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class NextPerfectSquare {

    //@ requires n >= 0;
 
    //@ ensures (\exists int k; k >= 0 && k * k > n; \result < k * k);  
    public static int nextPerfectSquare(int n) {
        int i = 1;
        int square = 1;
        //@ maintaining i > 0;
 
        //@ maintaining square > n ==> (\exists int k; k > 0; square == k * k && square > n);
 
        while (square <= n) {
            square = i * i;
            i++;
        }
        return square;
    }
}
