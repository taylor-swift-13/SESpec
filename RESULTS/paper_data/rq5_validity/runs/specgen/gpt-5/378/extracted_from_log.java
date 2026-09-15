import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SumInRange {

    //@ ensures \result == (\sum int k; l <= k && k <= r && k % 2 != 0; k);
    public static int sumInRange(int l, int r) {
        int sum = 0;
        //@ maintaining l <= i && i <= r + 1;
        //@ maintaining sum == (\sum int k; l <= k && k < i && k % 2 != 0; k);
        //@ decreases r - i + 1;
        for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
    }
}