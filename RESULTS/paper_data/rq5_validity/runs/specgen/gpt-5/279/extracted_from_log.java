import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

    //@ requires args != null && args.length >= 1;
    //@ ensures \result >= 0;
    //@ ensures \result <= (args[0] >= 0 ? args[0] : 0);
    /*@ spec_public @*/ public static int getGcd(int[] args) {
        int g = 0;
        int ret = args[0];
        //@ maintaining 1 <= j && j <= args.length;
        //@ maintaining 0 <= g;
        //@ maintaining g <= (args[0] >= 0 ? args[0] : 0);
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