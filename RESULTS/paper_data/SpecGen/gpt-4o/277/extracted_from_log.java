import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

    //@ requires arg != null && arg.length > 0;
    //@ ensures \forall int i; 0 < i && i < arg.length; \result + 1 >= arg[i] && arg[i] % \result == 0;  
    public static int getGcd(int[] arg) {
        int g = 0;
        int ret = arg[0];
        //@ maintaining 1 <= j && j <= arg.length;
        //@ maintaining (\forall int i; 0 <= i && i < j; ret <= arg[i]);
        //@ maintaining (\forall int i; 0 < i && i <= j; g > arg[i] && arg[i] % g == 0);  
        //@ decreases arg.length - j;
        for (int j = 1; j < arg.length; j++) {
            if (arg[j] > ret) {
                g = g > ret ? g : ret;
            } else {
                ret = arg[j];
            }
        }
        return g;
    }
}