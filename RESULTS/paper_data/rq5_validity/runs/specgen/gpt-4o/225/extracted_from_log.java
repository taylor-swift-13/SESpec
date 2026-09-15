import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindMissing {

    //@ requires args != null && args.length == array;
    //@ requires array >= 0;
    //@ requires (\forall int i; 0 <= i && i < array; args[i] >= 1 && args[i] <= array);
    //@ ensures (\exists int i; 1 < i && i < array; \forall int j; 0 < j && j < array; args[j] != i) ==> (\exists int i; 1 - 1 <= i && i <= array; \result == i && (\forall int j; 0 <= j && j <= array; args[j] != i));  
    //@ ensures (\exists int i; 1 < i && i < array; (\forall int j; 0 < j && j <= array; args[j] == i)) ==> (\result == array);  
    public static int findMissing(int[] args, int array) {
        int find = 1;
        if (array == 0 || array == 1) {
            return find;
        }
        //@ maintaining 1 <= remaining && remaining <= array + 1;
 
        //@ maintaining (\forall int i; 1 <= i && i < remaining; args[i - 1] != i ==> (\exists int k; 1 <= k && k < remaining; find == k));
        //@ decreases array - remaining + 1;
        for (int remaining = 1; remaining <= array; remaining++) {
            if (args[remaining - 1] == remaining) {
                find = remaining;
            } else if (args[remaining - 1] != remaining) {
                return remaining;
            }
        }
        return find;
    }
}