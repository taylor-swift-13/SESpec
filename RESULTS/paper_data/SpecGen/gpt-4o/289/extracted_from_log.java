import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalLucas {

    //@ requires c >= 0;
    //@ ensures \result == (c == 0 ? 2 : (c == 1 ? 1 : jacobsthalLucas(c - 1) + 2 * jacobsthalLucas(c - 2)));
    public static int jacobsthalLucas(int c) {
        int j[] = new int[c + 1];
        j[0] = 2;
        j[1] = 1;
        //@ maintaining 2 <= d && d <= c + 1;
        //@ maintaining (\forall int i; 2 <= i && i < d; j[i] == j[i-1] + 2 * j[i-2]);
        //@ decreases c - d + 1;
        for (int d = 2; d <= c; d++) {
            j[d] = j[d - 1]
                    + 2 * j[d - 2];
        }
        return j[c];
    }
}