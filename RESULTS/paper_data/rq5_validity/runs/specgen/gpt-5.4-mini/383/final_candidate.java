import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

    //@ requires n >= 0;
 
    public static int divisor(int n) {
        int count = 0;
        //@ maintaining 0 <= i && i <= n + 1;
        //@ maintaining 0 <= count && count <= i - 1;
 
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
    }
}
