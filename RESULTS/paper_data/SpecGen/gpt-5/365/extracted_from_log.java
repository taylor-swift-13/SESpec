import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

    //@ requires n >= 1;
    //@ ensures \result == (n + 1) / 2;
    public static int averageOdd(int n) {
        int sum = 0;
        int count = 0;
        //@ maintaining 1 <= i && i <= n + 1;
        //@ maintaining 0 <= count && 0 <= sum;
        //@ maintaining count == i / 2;
        //@ maintaining sum == count * count;
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
    }
}