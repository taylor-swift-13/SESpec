import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

    //@ requires n >= 1 && n <= 44;
    //@ ensures \result >= 1;
    public static int findLucas(int n) {
        int[] lucas = new int[n + 1];
        lucas[0] = 2;
        lucas[1] = 1;
        //@ maintaining lucas.length == n + 1;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining lucas[0] == 2 && lucas[1] == 1;
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        return lucas[n];
    }
}