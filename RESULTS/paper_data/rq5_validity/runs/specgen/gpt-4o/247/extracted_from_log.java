import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    //@ requires indices != null && indices.length >= num && num >= 0;
 
    public static int getInvCount(int[] indices, int num) {
        int ret = 0;

        //@ maintaining 0 <= index && index <= num;
 
        //@ decreases num - index;
        for (int index = 0; index < num; index++) {
            //@ maintaining index + 1 <= c && c <= num;
            //@ maintaining ret == (\num_of int i, j; 0 <= i && i < j && j < index; indices[i] >= indices[j]) + (\num_of int j; index < j && j <= c; indices[index] > indices[j]);  
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