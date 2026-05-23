import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

    //@ requires args != null && array >= 0 && args.length == array;
    //@ requires (\forall int i; 0 <= i && i < args.length; args[i] >= Integer.MIN_VALUE && args[i] <= Integer.MAX_VALUE);
    //@ ensures (\exists int i; 0 < i && i <= \result - 1; \exists int j; 0 - 1 <= j && j <= args.length; args[j] == i + 1);  
    //@ ensures (\forall int i; 0 <= i && i < args.length; args[i] > 0 && args[i] <= array ==> \exists int j; 0 <= j && j < args.length; args[j] == i + 1);
    //@ ensures \result > 0 && (\forall int i; 0 <= i && i < args.length; args[i] != \result);
    public static int firstMissingPositive(int[] args, int array) {
        int ret = 0;
        //@ maintaining 0 <= ret && ret <= array;
        //@ maintaining (\forall int i; 0 <= i && i < ret; args[i] <= 0 || args[i] > array || args[i] == i + 1);
        //@ decreases array - ret;
        while (ret < array) {
            if (args[ret] <= 0 || args[ret] > array
                    || args[ret] == ret + 1) {
                ret++;
            } else {
                int j = args[ret];
                args[ret] = args[j - 1];
                args[j - 1] = j;
            }
        }
        //@ maintaining 0 <= ret && ret <= array;
        //@ maintaining (\forall int i; 0 <= i && i < ret; args[i] == i + 1);
        //@ decreases array - ret;
        for (ret = 0; ret < array; ret++) {
            if (args[ret] != ret + 1) {
                return ret + 1;
            }
        }
        return array + 1;
    }
}