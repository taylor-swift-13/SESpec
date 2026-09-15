import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstDigit {

    //@ requires true;
    //@ ensures 0 <= \result && \result <= 9;
    //@ ensures num <= 1 ==> \result == 1;
    //@ ensures 0 <= num && num <= 12 ==> 1 <= \result && \result <= 9;
    /*@ spec_public @*/ public static int firstDigit(int num) {
        int first = 1;
        //@ maintaining 2 <= c && c <= num + 1;
        //@ maintaining c == 2 ==> first == 1;
        //@ decreases num - c + 1;
        for (int c = 2; c <= num; c++) {
            first *= c;
        }
        int result = 0;
        //@ maintaining first >= 0;
        //@ maintaining result >= 0 && result <= 9;
        //@ decreases first;
        while (first > 0) {
            result = first % 10;
            first /= 10;
        }
        return result;
    }
}