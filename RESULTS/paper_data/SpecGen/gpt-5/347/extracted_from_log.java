import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

    //@ requires y != Integer.MIN_VALUE;
    //@ ensures y >= 0;
    //@ ensures 0 <= \result && \result <= y;
    public static int findDivisor(int x, int y) {
        if (y < 0) {
            y = -y;
        }
        int count = 0;
        //@ maintaining y >= 0;
        //@ maintaining 1 <= i && i <= y + 1;
        //@ maintaining 0 <= count && count <= i - 1;
        //@ decreases y - i + 1;
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
    }
}