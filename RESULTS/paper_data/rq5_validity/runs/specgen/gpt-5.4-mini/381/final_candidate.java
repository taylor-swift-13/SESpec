import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class NumCommDiv {

    //@ requires x >= 0 && y >= 0;
    //@ ensures \result >= 0;
    //@ ensures \result <= x && \result <= y;
    //@ ensures \result == 0 <==> (\forall int i; 1 <= i && i < x && i < y; x % i != 0 && y % i != 0);  
    public static int numCommDiv(int x, int y) {
        int count = 0;
        //@ maintaining count >= 0;
        //@ maintaining count <= i - 1;
 
        //@ decreases (x < y ? x : y) - i + 1;
        for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
        return count;
    }
}
