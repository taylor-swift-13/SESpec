import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SeqLinear {

    //@ requires seqNums != null;
    //@ requires seqNums.length > 0;
    //@ ensures \result != null;
    //@ ensures \result.equals("Linear Sequence") || \result.equals("Non Linear Sequence");
    public static String seqLinear(int[] seqNums) {
        if (seqNums.length == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        for (int i = 1; i < seqNums.length; i++) {
            if (seqNums[i] - seqNums[i - 1] != difference) {
                return "Non Linear Sequence";
            }
        }
        return "Linear Sequence";
    }
}