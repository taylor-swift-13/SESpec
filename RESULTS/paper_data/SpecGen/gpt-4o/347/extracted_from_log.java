import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

    //@ requires y != 0;
 
 
    public static int findDivisor(int x, int y) {
        if (y < 0) {
            y = -y;
        }
        int count = 0;
        //@ maintaining 1 <= i && i <= y + 1;
 
        //@ decreases y - i + 1;
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
    }
}