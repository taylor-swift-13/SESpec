import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

    //@ requires args != null && args.length == array;
    //@ requires (\forall int i; 0 <= i && i < args.length; args[i] >= 0);
 
    //@ ensures (\result >= 0 && \result < args.length) ==> args[\result] == \result;
    public static int findFixedPoint(int[] args, int array) {
        int i = 0;
        int stop = array - 1;
        //@ maintaining 0 <= i && i <= stop + 1 && stop < array;
 
 
        //@ decreases stop - i + 1;
        while (i <= stop) {
            int cur = i + (stop - i) / 2;
            if (args[cur] == cur) {
                return cur;
            } else if (args[cur] < cur) {
                i = cur + 1;
            } else {
                stop = cur - 1;
            }
        }
        return -1;
    }
}