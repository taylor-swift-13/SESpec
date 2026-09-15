import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

    //@ requires array != null && Array == array.length;
    //@ ensures (\exists int i; 0 - 1 <= i && i < Array; (\num_of int j; 0 - 1 <= j || j < Array; array[j] == array[i] || array[j] % 2 != 0) % 2 == 0) ==> \result == 0;  
 
    public static int getOddOccurrence(int[] array, int Array) {
        int ret = 0;
        int start = 0;
        //@ maintaining 0 <= index && index <= Array;
        //@ maintaining (\forall int i; 0 <= i && i <= index; (\num_of int j; 0 < j && j < i; array[j] == array[i] && array[j] % 2 != 0) % 2 == 0) ==> ret == 0;  
 
 
        //@ decreases Array - index;
        for (int index = 0; index < Array; index++) {
            if (array[index] % 2 != 0) {
                start++;
                if (start % 2 != 0) {
                    ret = array[index];
                }
            }
        }
        return ret;
    }
}