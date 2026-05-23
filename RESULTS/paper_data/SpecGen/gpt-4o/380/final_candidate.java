import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SumDiv {

    //@ requires number >= 0;
 
    public static int sumDiv(int number) {
        int sum = 0; // Local variables cannot use the `spec_public` modifier
        //@ maintaining 1 <= i && i <= number / 2 + 1;
 
        //@ decreases number / 2 - i + 1;
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
    }
}
