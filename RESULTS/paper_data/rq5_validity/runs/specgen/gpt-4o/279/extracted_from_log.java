import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

    //@ requires args.length > 0;
 
 
    public static int getGcd(int[] args) {
        int g = 0;
        int ret = args[0];
        //@ maintaining 1 <= j && j <= args.length;
        //@ maintaining \forall int i; 0 <= i && i < j; ret <= args[i];
        //@ maintaining \exists int i; 0 <= i && i < j; ret == args[i];
        //@ decreases args.length - j;
        for (int j = 1; j < args.length; j++) {
            if (args[j] > ret) {
                g = g > ret ? g : ret;
            } else {
                ret = args[j];
            }
        }
        return g;
    }
}