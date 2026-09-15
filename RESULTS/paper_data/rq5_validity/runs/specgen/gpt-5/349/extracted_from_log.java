import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SumOfOddFactors {

    //@ ensures n <= 0 ==> \result == 0;
    //@ ensures n > 0 ==> \result == (\sum int k; 1 <= k && k <= n && n % k == 0 && k % 2 != 0; k);
    //@ ensures \result >= 0;
    /*@ spec_public @*/ public static int sumOfOddFactors(int n) {
        int sum = 0;
        //@ maintaining 1 <= i && i <= n + 1;
        //@ maintaining sum == (\sum int k; 1 <= k && k < i && n % k == 0 && k % 2 != 0; k);
        //@ maintaining sum >= 0;
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
        return sum;
    }
}