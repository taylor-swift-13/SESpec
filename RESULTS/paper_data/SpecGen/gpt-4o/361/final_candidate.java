import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

    //@ requires size >= 0;
    //@ ensures \result == (\sum int j; 1 <= j && j <= size && j % 2 == 0; j) / (\num_of int j; 1 <= j && j <= size && j % 2 == 0; true);
    //@ ensures size == 0 || (\forall int j; 1 <= j && j <= size && j % 2 == 0; \result >= 0);
    public static int averageEven(int size) {
        int average = 0;
        int total = 0;

        //@ maintaining 1 <= j && j <= size + 1;
 
 
        //@ decreases size - j + 1;
        for (int j = 1; j <= size; j++) {
            if (j % 2 == 0) {
                average += j;
                total++;
            }
        }

        //@ assert total > 0 ==> average / total == (\sum int j; 1 <= j && j <= size && j % 2 == 0; j) / (\num_of int j; 1 <= j && j <= size && j % 2 == 0; true);
        return average / total;
    }
}
