import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class ComputeLastDigit {

    //@ ensures (a == b) ==> \result == 1;
 
    //@ ensures (a != b && (b - a) < 5) ==> 0 - 1 <= \result && \result < 10;  
    public static int computeLastDigit(int a, int b) {
        int variable = 1;
        if (a == b) {
            return 1;
        } else if ((b - a) >= 5) {
            return 0;
        } else {
 
 
 
            //@ decreases b + 1 - i;
            for (int i = a + 1; i < b + 1; i++) {
                variable = (variable * (i % 10)) % 10;
            }
            return variable % 10;
        }
    }
}