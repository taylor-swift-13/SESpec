import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

    //@ requires args != null && args.length == array;
    //@ requires (\forall int i; 0 <= i && i < args.length; args[i] >= 1 && args[i] <= array);
    //@ requires (\forall int i, j; 0 <= i && i < j && j < args.length; args[i] != args[j]);
    //@ ensures (\forall int i; 1 < i && i < array; (\exists int j; 0 < j && j < args.length; args[j] != i) ==> \result == i);  
    //@ ensures (\forall int i; 1 <= i && i <= array; (\exists int j; 0 <= j && j < args.length; args[j] == i) ==> \result != i);
    public static int findMissing(int[] args, int array) {
        int found = 1;
        if (array == 0 || array == 1) {
            return found;
        }
        //@ maintaining 1 <= num && num <= array + 1;
        //@ maintaining (\forall int i; 1 < i && i < num; (\exists int j; 0 < j && j < args.length; args[j] == i) ==> found == i);  
        //@ maintaining (\forall int i; 1 <= i && i < num; (\forall int j; 0 <= j && j <= args.length; args[j] != i));  
        //@ decreases array - num + 1;
        for (int num = 1; num <= array; num++) {
            if (args[num - 1] == num) {
                found = num;
            } else if (args[num - 1] != num) {
                return num;
            }
        }
        return found;
    }
}