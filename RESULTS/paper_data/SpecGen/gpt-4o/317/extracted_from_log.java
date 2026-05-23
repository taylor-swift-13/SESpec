import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

    //@ requires num > 0;
    //@ ensures \result >= 0;
 
    public static int countFac(int num) {
        int result = 0;
        if (num == 1)
            return 1;
        //@ maintaining 2 <= size && size - 1 <= num / size + 1;  
        //@ maintaining result >= 0;
 
        //@ decreases num / size - size + 1;
        for (int size = 2; size <= num / size; size++) {
            if (num % size == 0) {
                result++;
                if (num / size == size) {
                    break;
                }
            }
        }
        return result;
    }
}