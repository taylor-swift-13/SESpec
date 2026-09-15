import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageOdd {

    //@ requires size > 0;
    //@ ensures \result == (\sum int i; 1 <= i && i <= size && i % 2 != 0; i) / (\num_of int i; 1 <= i && i <= size && i % 2 != 0);
    public static int averageOdd(int size) {
        int average = 0;
        int total = 0;

        //@ maintaining 1 <= c && c <= size + 1;
 
 
        //@ decreases size - c + 1;
        for (int c = 1; c <= size; c++) {
            if (c % 2 != 0) {
                average += c;
                total++;
            }
        }
        return average / total;
    }
}
