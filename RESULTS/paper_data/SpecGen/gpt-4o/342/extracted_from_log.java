import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

    //@ requires code > 0 && b >= 0 && l <= m;
    //@ ensures \result == -1 <==> (\forall int c; l - 1 <= c && c - 1 <= m; c % code == 0 || (\num_of int x; l <= x && x - 1 <= c && x % code != 0) < b);  
    //@ ensures \result != -1 ==> (\num_of int x; l <= x && x <= \result && x % code != 0) == b;
    public static int countNo(int code, int b, int l, int m) {
        int result = 0;
        //@ maintaining l <= c && c <= m + 1;
        //@ maintaining result >= 0 && result <= b;
        //@ maintaining (\forall int x; l <= x && x < c; x % code == 0 || (\num_of int y; l <= y && y <= x && y % code != 0) <= result);
        //@ decreases m - c + 1;
        for (int c = l; c <= m; c++) {
            if (c % code != 0) {
                result++;
            }
            if (result == b) {
                return c;
            }
        }
        return -1;
    }
}