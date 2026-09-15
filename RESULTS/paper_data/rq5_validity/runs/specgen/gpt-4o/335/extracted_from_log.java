import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ComputeLastDigit {

    //@ requires a >= 0 && b >= 0 && a <= b;
    //@ ensures (a == b) ==> (\result == 1);
    //@ ensures ((b - a) >= 5) ==> (\result == 0);
 
    public static int computeLastDigit(int a, int b) {
        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
            //@ maintaining a + 1 <= i && i <= b + 1;
 
            //@ decreases b + 1 - i;
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
    }
}