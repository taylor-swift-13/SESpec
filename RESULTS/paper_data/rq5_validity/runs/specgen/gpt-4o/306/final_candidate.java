import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

    //@ requires n >= 0;
    //@ ensures \result == 2 <==> n == 0;
    //@ ensures \result == 1 <==> n == 1;
    //@ ensures n >= 2 ==> \result == findLucas(n - 1) + findLucas(n - 2);
    public static int findLucas(int n) {
        int[] lucas = new int[n + 1];
        //@ assert lucas.length == n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining (\forall int k; 0 <= k && k < i; (k == 0 ==> lucas[k] == 2) && (k == 1 ==> lucas[k] == 1) && (k >= 2 ==> lucas[k] == lucas[k - 1] + lucas[k - 2]));
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        //@ assert lucas[n] == (n == 0 ? 2 : (n == 1 ? 1 : lucas[n - 1] + lucas[n - 2]));
        return lucas[n];
    }
}