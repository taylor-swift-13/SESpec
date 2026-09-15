import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    //@ requires args != null && args.length == num && num >= 0;
 
    public static int getInvCount(int[] args, int num) {
        int ret = 0;

        //@ maintaining 0 <= index && index <= num;
 
        //@ decreases num - index;
        for (int index = 0; index < num; index++) {
            //@ maintaining index + 1 <= k && k <= num;
            //@ maintaining ret == (\sum int i, j; 0 < i && i <= j && j <= index; args[i] > args[j] ? 1 : 0) + (\sum int j; index + 1 < j && j <= k; args[index] > args[j] ? 1 : 0);  
            //@ decreases num - k;
            for (int k = index + 1; k < num; k++) {
                if (args[index] > args[k]) {
                    ret++;
                }
            }
        }
        return ret;
    }
}