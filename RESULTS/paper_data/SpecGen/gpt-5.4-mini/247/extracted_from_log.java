import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    //@ requires indices != null;
    //@ requires 0 <= num && num <= indices.length;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int i; 0 <= i && i < num;
    //@                     (\sum int j; i < j && j < num;
    //@                         (indices[i] > indices[j] ? 1 : 0)));
    public static int getInvCount(int[] indices, int num) {
        int ret = 0;

 
 
        //@                         (\sum int j; i < j && j < num;
        //@                             (indices[i] > indices[j] ? 1 : 0)));
        //@ decreases num - index;
        for (int index = 0; index < num; index++) {
            //@ loop_invariant index + 1 <= c && c <= num + 1;
            //@ loop_invariant ret == (\sum int i; 0 <= i && i < index;
            //@                         (\sum int j; i < j && j < num;
            //@                             (indices[i] > indices[j] ? 1 : 0)))
            //@                     + (\sum int j; index < j && j < c;
            //@                         (indices[index] > indices[j] ? 1 : 0));
            //@ decreases num - c;
            for (int c = index + 1; c < num; c++) {
                if (indices[index] > indices[c]) {
                    ret++;
                }
            }
        }
        return ret;
    }
}