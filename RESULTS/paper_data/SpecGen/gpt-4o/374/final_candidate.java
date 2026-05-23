import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

    //@ requires number > 0;
 
    public static int divisor(int number) {
        int div = 0;
        //@ maintaining 1 <= c && c <= number + 1;
 
        //@ decreases number - c + 1;
        for (int c = 1; c <= number; c++) {
            if (number % c == 0) {
                div++;
            }
        }
        return div;
    }
}
