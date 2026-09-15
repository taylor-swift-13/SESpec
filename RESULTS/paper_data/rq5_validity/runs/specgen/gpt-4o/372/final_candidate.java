import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Divisor {

    //@ requires num > 0;
 
 
    public static int divisor(int num) {
        int div = 0;
        //@ maintaining 1 <= c && c <= num + 1;
 
        //@ decreases num - c + 1;
        for (int c = 1; c <= num; c++) {
            if (num % c == 0) {
                div++;
            }
        }
        return div;
    }
}
