import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

    /*@ spec_public @*/
    //@ requires n > 0;
    //@ ensures \result == (\sum int i; 1 <= i && i <= n; (n % i == 0 ? 1 : 0));
    //@ ensures 1 <= \result && \result <= n;
    public static int divisor(int n) {
        int count = 0;
        //@ maintaining 1 <= i && i <= n + 1;
        //@ maintaining count == (\sum int j; 1 <= j && j < i; (n % j == 0 ? 1 : 0));
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
    }
}