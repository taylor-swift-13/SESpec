import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Sum {

    //@ requires n >= 0;
    //@ ensures \result == (\sum int p; 2 <= p && p <= n && (\forall int d; 2 <= d && d < p ==> p % d != 0) && n % p == 0; p);
    //@ ensures 0 <= \result && \result <= n;
    public static int sum(int n) {
        int[] sumOfPrimeDivisors = new int[n + 1];
        //@ assume 0 < sumOfPrimeDivisors.length;
        sumOfPrimeDivisors[0] = 0;
        //@ assume 1 < sumOfPrimeDivisors.length;
        sumOfPrimeDivisors[1] = 0;

        //@ maintaining sumOfPrimeDivisors.length == n + 1;
        //@ maintaining sumOfPrimeDivisors[0] == 0 && sumOfPrimeDivisors[1] == 0;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining (\forall int m; 0 <= m && m < i;
        //@                 sumOfPrimeDivisors[m] ==
        //@                   (\sum int p; 2 <= p && p <= m &&
        //@                                  (\forall int d; 2 <= d && d < p ==> p % d != 0) &&
        //@                                  m % p == 0; p));
        //@ maintaining (\forall int m; i <= m && m <= n;
        //@                 sumOfPrimeDivisors[m] ==
        //@                   (\sum int p; 2 <= p && p < i &&
        //@                                  (\forall int d; 2 <= d && d < p ==> p % d != 0) &&
        //@                                  m % p == 0; p));
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            //@ assume 0 <= i && i < sumOfPrimeDivisors.length;
            if (sumOfPrimeDivisors[i] == 0) {
                //@ maintaining i >= 2 && i <= n;
                //@ maintaining j % i == 0 && i <= j;
                //@ maintaining sumOfPrimeDivisors[0] == 0 && sumOfPrimeDivisors[1] == 0;
                //@ maintaining (\forall int m; 0 <= m && m < i;
                //@                 sumOfPrimeDivisors[m] ==
                //@                   (\sum int p; 2 <= p && p <= m &&
                //@                                  (\forall int d; 2 <= d && d < p ==> p % d != 0) &&
                //@                                  m % p == 0; p));
                //@ maintaining (\forall int m; i <= m && m <= n;
                //@                 sumOfPrimeDivisors[m] ==
                //@                   (\sum int p; 2 <= p && p < i &&
                //@                                  (\forall int d; 2 <= d && d < p ==> p % d != 0) &&
                //@                                  m % p == 0; p)
                //@                   + ((m % i == 0 && m < j) ? i : 0));
                //@ decreases n - j + 1;
                for (int j = i; j <= n; j += i) {
                    //@ assume 0 <= j && j < sumOfPrimeDivisors.length;
                    sumOfPrimeDivisors[j] += i;
                }
            }
        }

        //@ assume 0 <= n && n < sumOfPrimeDivisors.length;
        return sumOfPrimeDivisors[n];
    }
}