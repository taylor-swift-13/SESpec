import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountDigit {

    //@ requires number >= 0;
    //@ ensures \result >= 0;
 
 
    public static int countDigit(int number) {
        int ret = 0;
        //@ maintaining number >= 0;
        //@ maintaining ret >= 0;
 
        //@ decreases number;
        while (number > 0) {
            number /= 10;
            ret++;
        }
        return ret;
    }
}
