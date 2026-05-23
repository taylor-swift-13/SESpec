import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    //@ requires args != null && args.length == num;
    //@ requires num >= 0;
 
    public static int getInvCount(int[] args, int num) {
        int ret = 0;

        //@ maintaining 0 <= index && index <= num;
 
        //@ decreases num - index;
        for (int index = 0; index < num; index++) {
            //@ maintaining index + 1 <= c && c <= num;
            //@ maintaining ret == (\sum int i, j; 0 <= i && i <= j && j < num && i <= index || (i == index && j < c); args[i] > args[j] ? 1 : 0);  
            //@ decreases num - c;
            for (int c = index + 1; c < num; c++) {
                if (args[index] > args[c]) {
                    ret++;
                }
            }
        }
        return ret;
    }
}