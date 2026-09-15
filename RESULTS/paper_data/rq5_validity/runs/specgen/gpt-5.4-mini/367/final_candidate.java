import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestDivisor {

    //@ requires n >= 2;
    //@ ensures \result == n || (\result >= 2 && \result <= n && n % \result == 0);
 
    public static int smallestDivisor(int n) {
        int i = 2;
        //@ maintaining 2 <= i;
        //@ maintaining i <= n + 1;
 
        //@ decreasing n / i - i;
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
    }
}
