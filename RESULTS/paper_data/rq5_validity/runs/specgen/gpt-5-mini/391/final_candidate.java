import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class NextPerfectSquare {

    //@ requires true;
    //@ ensures \result > n;
    //@ ensures \exists int k; k >= 1 && \result == k * k;
    //@ ensures (\forall int j; j >= 1 && j * j < \result ==> j * j <= n);
    public static int nextPerfectSquare(int n) {
        int i = 1;
        int square = 1;
        //@ maintaining i >= 1;
        //@ maintaining square >= 0;
        //@ maintaining square == i * i || square == (i - 1) * (i - 1);
        //@ decreases Integer.MAX_VALUE - i;
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
    }
}