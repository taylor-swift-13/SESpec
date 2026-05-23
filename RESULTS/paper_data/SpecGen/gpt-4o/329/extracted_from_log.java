import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Difference {

    //@ requires diff >= 0;
 
    public static int difference(int diff) {
        int ret = 0;
        int max = 0;

        //@ maintaining 1 <= j && j <= diff + 1;
 
        //@ decreases diff - j + 1;
        for (int j = 1; j <= diff; j++) {
            ret += j * j * j;
        }

        //@ maintaining 1 <= j && j <= diff + 1;
 
        //@ decreases diff - j + 1;
        for (int j = 1; j <= diff; j++) {
            max += j;
        }

        return ret - max;
    }
}