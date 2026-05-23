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
        if (c == 0) {
            return 2;
        }
        if (c == 1) {
            return 1;
        }
        int prev2 = 2; // N[0]
        int prev1 = 1; // N[1]
        int current = 0;

        //@ maintaining 2 <= i && i <= c + 1;
        //@ maintaining current == prev1 + 2 * prev2;
        //@ decreases c - i + 1;
        for (int i = 2; i <= c; i++) {
            current = prev1 + 2 * prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
}