import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

    /*@ spec_public @*/ public static int averageOdd(int size) {
        //@ requires size > 0;
        //@ requires (\num_of int i; 1 <= i && i <= size && i % 2 != 0; true) > 0;
        //@ ensures (\num_of int i; 1 < i && i - 1 <= size && i % 2 != 0; true) >= 0 ==> \result == (\sum int i; 1 < i && i - 1 <= size && i % 2 != 0; i) / (\num_of int i; 1 - 1 <= i && i < size && i % 2 != 0; true);  
        int ret = 0;
        int total = 0;
 
 
        //@ maintaining total == (\num_of int i; 1 < i && i <= c && i % 2 != 0; true);  
        //@ decreases size - c + 1;
        for (int c = 1; c <= size; c++) {
            if (c % 2 != 0) {
                ret += c;
                total++;
            }
        }
        return ret / total;
    }
}
