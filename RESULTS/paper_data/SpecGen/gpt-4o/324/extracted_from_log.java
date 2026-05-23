import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstDigit {

    //@ requires number >= 0;
    //@ ensures \result >= 0 && \result <= 9;
    public static int firstDigit(int number) {
        int first = 1;
        //@ maintaining 1 < c && c - 1 <= number + 1;  
 
        //@ decreases number - c + 2;
        for (int c = 2; c <= number; c++) {
            first *= c;
        }
        int result = 0;
 
        //@ maintaining result >= 0 && result <= 9;
        //@ decreases first;
        while (first > 0) {
            result = first % 10;
            first /= 10;
        }
        return result;
    }
}