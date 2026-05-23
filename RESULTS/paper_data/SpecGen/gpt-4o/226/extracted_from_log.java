import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

    //@ requires args != null && args.length == array;
    //@ requires array >= 0;
    //@ requires (\forall int i; 0 <= i && i < array; args[i] >= 1 && args[i] <= array);
    //@ ensures (\exists int i; 1 < i && i - 1 <= array; \result == i && (\forall int j; 1 < j && j <= i; args[j - 1] == j) && args[i - 1] != i) || (\result == array && (\forall int i; 1 <= i && i <= array; args[i - 1] == i));  
    public static int findMissing(int[] args, int array) {
        int found = 1;
        if (array == 0 || array == 1) {
            return found;
        }
        //@ maintaining 1 <= remaining && remaining <= array + 1;
        //@ maintaining (\forall int i; 1 <= i && i < remaining; args[i - 1] == i || found == i);
        //@ decreases array - remaining + 1;
        for (int remaining = 1; remaining <= array; remaining++) {
            if (args[remaining - 1] == remaining) {
                found = remaining;
            } else if (args[remaining - 1] != remaining) {
                return remaining;
            }
        }
        return found;
    }
}