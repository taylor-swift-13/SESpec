import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LastTwoDigits {

    //@ requires num >= 0;
 
 
    public static int lastTwoDigits(int num) {
        int ret = 1;
 
        //@ maintaining 1 <= number && number <= num + 1;
        //@ decreases num - number + 1;
        for (int number = 1; number <= num; number++) {
            ret *= number;
        }
        int result = (int) (ret % 100);
        return result;
    }
}
