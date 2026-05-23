import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Sum {

    //@ requires n >= 1;
 
 
    public static int sum(int n) {
        int[] sumOfPrimeDivisors = new int[n + 1];
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;

        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining sumOfPrimeDivisors.length == n + 1;
 
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                //@ maintaining i <= j && j <= n + i;
 
                //@ decreases n - j + i;
                for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        return sumOfPrimeDivisors[n];
    }
}