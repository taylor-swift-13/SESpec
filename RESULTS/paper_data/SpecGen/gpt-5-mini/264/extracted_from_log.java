import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SeqLinear {

    //@ requires seqNums != null;
    //@ requires seqNums.length >= 1;
    //@ ensures \result != null;
    //@ ensures \result.equals("Linear Sequence") || \result.equals("Non Linear Sequence");
    //@ ensures seqNums.length == 1 ==> \result.equals("Linear Sequence");
    public static String seqLinear(int[] seqNums) {
        if (seqNums.length == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        //@ maintaining 1 <= i && i <= seqNums.length;
        //@ decreases seqNums.length - i;
        for (int i = 1; i < seqNums.length; i++) {
            if (seqNums[i] - seqNums[i - 1] != difference) {
                return "Non Linear Sequence";
            }
        }
        return "Linear Sequence";
    }
}