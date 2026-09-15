import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDivisors {

    /*@ public normal_behavior
      @   requires n >= 0;
      @   ensures \result.equals("Even") || \result.equals("Odd");
      @*/
    public static String countDivisors(int n) {
        int count = 0;
        //@ maintaining 1 <= i && i <= n + 1;
        //@ maintaining count >= 0;
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
    }
}