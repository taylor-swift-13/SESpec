import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

    //@ requires n > 0;
 
    public static int countFac(int n) {
        int count = 0;
        if (n == 1) return 1;
        //@ maintaining 2 <= i && i - 1 <= n / i + 1;  
 
        //@ decreases n / i - i + 1;
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