import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPairsCount {

    //@ requires array != null && num >= 0 && num <= array.length;
 
 
    public static int getPairsCount(int[] array, int num, int p) {
        int ret = 0;
        //@ maintaining 0 <= index && index <= num;
 
        //@ decreases num - index;
        for (int index = 0; index < num; index++) {
            //@ maintaining index + 1 <= inner && inner <= num;
            //@ maintaining ret == (\num_of int i, j; 0 <= i && i < j && j < num && (i <= index || (i == index && j <= inner)) && array[i] - array[j] == p; true);  
            //@ decreases num - inner;
            for (int inner = index + 1; inner < num; inner++) {
                if (array[index] + array[inner] == p) {
                    ret++;
                }
            }
        }
        return ret;
    }
}