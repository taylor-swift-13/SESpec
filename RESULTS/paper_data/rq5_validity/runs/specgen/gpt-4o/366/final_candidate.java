import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

    //@ requires n > 0;
    //@ ensures \result == (\sum int i; 1 <= i && i <= n && i % 2 == 0; i) / (\num_of int i; 1 <= i && i <= n && i % 2 == 0);
    public static int averageEven(int n) {
        int sum = 0;
        int count = 0;

        //@ maintaining 1 <= i && i <= n + 1;
 
 
        //@ decreases n - i + 1;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        //@ assert count > 0; // Ensures division by zero does not occur
        return sum / count;
    }
}
