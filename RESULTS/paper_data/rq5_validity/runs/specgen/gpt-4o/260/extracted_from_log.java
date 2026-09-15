import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

    //@ requires args != null && args.length > 0;
    //@ requires 0 <= array && array <= args.length;
 
    //@ ensures 0 <= \result && \result < array ==> args[\result] == \result;
    public static int findFixedPoint(int[] args, int array) {
        int ret = 0;
        int stop = array - 1;
        //@ maintaining 0 <= ret && ret <= stop + 1 && stop < array;
 
 
        //@ decreases stop - ret + 1;
        while (ret <= stop) {
            int i = ret + (stop - ret) / 2;
            if (args[i] == i) {
                return i;
            } else if (args[i] < i) {
                ret = i + 1;
            } else {
                stop = i - 1;
            }
        }
        return -1;
    }
}