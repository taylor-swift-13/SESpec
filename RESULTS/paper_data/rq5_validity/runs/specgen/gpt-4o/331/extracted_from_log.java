import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ComputeLastDigit {

    //@ requires n >= 0 && c >= 0 && n <= c;
 
    //@ ensures \result == 0 <==> (c - n) >= 5;
    //@ ensures n < c && (c - n) < 5 ==> \result == (\product int i; n+1 <= i && i <= c; (i % 10)) % 10;
    public static int computeLastDigit(int n, int c) {
        int result = 1;
        if (n == c) {
            return 1;
        } else if ((c - n) >= 5) {
            return 0;
        } else {
            //@ maintaining n + 1 <= index && index <= c + 1;
 
            //@ decreases c + 1 - index;
            for (int index = n + 1; index < c + 1; index++) {
                result = (result * (index % 10)) % 10;
            }
            return result % 10;
        }
    }
}