import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SumInRange {

    //@ requires l <= r;
 
    public static int sumInRange(int l, int r) {
        int sum = 0;
        //@ maintaining l <= i && i <= r + 1;
 
        //@ decreases r - i + 1;
        for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
    }
}
