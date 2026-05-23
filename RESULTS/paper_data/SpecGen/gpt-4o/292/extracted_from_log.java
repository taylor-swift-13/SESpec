import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

    //@ requires seed >= 0;
    //@ ensures (\exists int[] p; p.length == seed + 1 && p[0] == 0 && p[1] == 1 && (\exists int count; 2 < count && count < seed; p[count] == (2 * p[count - 1] + p[count - 2]) % 1000000000) || \result == p[seed]);  
    public static int getPell(int seed) {
        int[] p = new int[seed + 1];
        //@ assert p.length == seed + 1;
        //@ assume 1 < p.length;
        p[0] = 0;
        //@ assume 1 < p.length;
        p[1] = 1;
        //@ maintaining 2 <= count && count <= seed + 1;
 
        //@ decreases seed - count + 1;
        for (int count = 2; count <= seed; count++) {
            //@ assume count < p.length;
            p[count] = (2 * p[count - 1]
                    + p[count - 2]) % 1000000000;
        }
        return p[seed];
    }
}