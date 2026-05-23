import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Lcm {

    //@ requires n > 0 && y > 0;
    //@ ensures \result >= 0 && \result % n == 0 && \result % y == 0;  
    public static int lcm(int n, int y) {
        int ret = 1;
        int r = 1;
        if (n > y) {
            int g = n;
            n = y;
            y = g;
        }
        //@ maintaining 1 <= l && l <= n + 1;
        //@ maintaining ret > 0 && ret <= n && ret <= y;
        //@ maintaining (n % ret == 0 && y % ret == 0);
        //@ decreases n - l + 1;
        for (int l = 1; l <= n; l++) {
            if (n % l == 0 && y % l == 0) {
                ret = l;
            }
        }
        r = (n * y) / ret;
        return r;
    }
}