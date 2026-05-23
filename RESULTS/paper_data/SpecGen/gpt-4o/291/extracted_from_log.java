import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalLucas {

    //@ requires c >= 0;
    //@ ensures \result == 2 <==> c == 0;
    //@ ensures \result == 1 <==> c == 1;
    //@ ensures c >= 2 ==> \result == jacobsthalLucas(c - 1) + 2 * jacobsthalLucas(c - 2);
    public static int jacobsthalLucas(int c) {
        int j[] = new int[c + 1];
        j[0] = 2;
        j[1] = 1;
        //@ maintaining 2 <= p && p <= c + 1;
        //@ maintaining (\forall int n; 0 <= n && n < p; j[n] == (n == 0 ? 2 : (n == 1 ? 1 : j[n - 1] + 2 * j[n - 2])));
        //@ decreases c - p + 1;
        for (int p = 2; p <= c; p++) {
            j[p] = j[p - 1] + 2 * j[p - 2];
        }
        return j[c];
    }
}