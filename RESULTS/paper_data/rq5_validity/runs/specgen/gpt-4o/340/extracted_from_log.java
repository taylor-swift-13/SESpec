import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

    //@ requires z != 0;
 
 
    public static int findDivisor(int n, int z) {
        if (z < 0) {
            z = -z;
        }
        int result = 0;
        //@ maintaining 1 <= loop && loop <= z + 1;
 
        //@ decreases z - loop + 1;
        for (int loop = 1; loop <= z; loop++) {
            if (n % loop == 0) {
                result = result + 1;
            }
        }
        return result;
    }
}