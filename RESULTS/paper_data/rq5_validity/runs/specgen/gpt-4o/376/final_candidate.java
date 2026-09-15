import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BinomialCoeff {

    //@ requires seed >= 0 && m >= 0 && m <= seed;
 
    public static int binomialCoeff(int seed, int m) {
        if (m > seed - m)
            m = seed - m;
        int b = 1;
        //@ maintaining 1 <= r && r <= m + 1;
 
        //@ decreases m - r + 1;
        for (int r = 1; r <= m; r++) {
            b = b * (seed - r + 1) / r;
        }
        return b;
    }
}
