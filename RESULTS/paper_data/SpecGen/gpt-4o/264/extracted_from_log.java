import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SeqLinear {

    //@ requires seqNums != null && seqNums.length > 0;
    //@ ensures (\result.equals("Linear Sequence") ==> (\forall int i; 1 <= i && i < seqNums.length; seqNums[i] - seqNums[i-1] == seqNums[1] - seqNums[0]));
    //@ ensures (\result.equals("Non Linear Sequence") ==> (\exists int i; 1 <= i && i < seqNums.length; seqNums[i] - seqNums[i-1] != seqNums[1] - seqNums[0]));
    public static String seqLinear(int[] seqNums) {
        if (seqNums.length == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        //@ maintaining 1 <= i && i <= seqNums.length;
        //@ maintaining (\forall int j; 1 <= j && j < i; seqNums[j] - seqNums[j-1] == difference);
        //@ decreases seqNums.length - i;
        for (int i = 1; i < seqNums.length; i++) {
            if (seqNums[i] - seqNums[i - 1] != difference) {
                return "Non Linear Sequence";
            }
        }
        return "Linear Sequence";
    }
}