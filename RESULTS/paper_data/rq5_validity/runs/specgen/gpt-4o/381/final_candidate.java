import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class NumCommDiv {

    //@ requires x > 0 && y > 0;
 
 
    public static int numCommDiv(int x, int y) {
        int count = 0;
        //@ maintaining 1 <= i && i <= x + 1 && i <= y + 1;
 
        //@ decreases (x < y ? x : y) - i + 1;
        for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
        return count;
    }
}
