import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

    //@ requires n >= 1;
    //@ ensures n == 1 ==> \result == 1;
 
    //@ ensures \result >= 0;
    public static int countFac(int n) {
        int count = 0;
        if (n == 1) return 1;
        //@ maintaining 2 <= i && i <= n + 1;
 
        //@ maintaining count >= 0;
        //@ decreases n - i + 1;
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
        return count;
    }
}