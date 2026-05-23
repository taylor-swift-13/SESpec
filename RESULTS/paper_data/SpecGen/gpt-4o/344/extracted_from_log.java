import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

    //@ requires code > 0 && b >= 0 && l <= m;
    //@ ensures \result == -1 <==> (\forall int c; l <= c && c - 1 <= m; c % code == 0 || (\num_of int i; l <= i && i - 1 <= c && i % code != 0) < b);  
    //@ ensures \result != -1 ==> (\num_of int i; l <= i && i <= \result && i % code != 0) == b;
    public static int countNo(int code, int b, int l, int m) {
        int ret = 0;
        //@ maintaining l <= c && c <= m + 1;
        //@ maintaining 0 <= ret && ret <= b;
        //@ maintaining (\forall int i; l <= i && i < c; i % code != 0 ==> (\num_of int j; l <= j && j <= i && j % code != 0) <= ret);
        //@ maintaining (\forall int i; l <= i && i < c; i % code == 0 ==> (\num_of int j; l <= j && j <= i && j % code != 0) == ret);
        //@ decreases m - c + 1;
        for (int c = l; c <= m; c++) {
            if (c % code != 0) {
                ret++;
            }
            if (ret == b) {
                return c;
            }
        }
        return -1;
    }
}