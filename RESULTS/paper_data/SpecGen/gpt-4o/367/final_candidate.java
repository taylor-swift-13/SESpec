import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SmallestDivisor {

    //@ requires n > 1;
    //@ ensures \result >= 2 && \result <= n;
    //@ ensures n % \result == 0;
 
    public static int smallestDivisor(int n) {
        int i = 2;
        //@ maintaining 2 <= i && i - 1 <= n / i + 1;  
        //@ maintaining (\forall int j; 2 <= j && j < i; n % j != 0);
        //@ decreases n / i - i + 1;
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
    }
}
