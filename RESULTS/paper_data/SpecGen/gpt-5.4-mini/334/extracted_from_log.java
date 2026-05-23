import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

    //@ requires n >= 0;
    //@ ensures \result == ((\sum int i; 1 - 1 <= i && i < n; i * i * i) + (\sum int i; 1 < i && i - 1 <= n; i));  
    public static int difference(int n) {
        int sum = 0;
        int sum1 = 0;
        //@ maintaining 0 <= i && i <= n + 1;
 
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        //@ maintaining 0 <= i && i <= n + 1;
 
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
    }
}