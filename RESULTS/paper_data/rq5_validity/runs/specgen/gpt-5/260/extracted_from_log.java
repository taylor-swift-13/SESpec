import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFixedPoint {

    /*@ 
      @  requires args != null;
      @  requires 0 <= array && array <= args.length;
      @  // strictly increasing over the searched prefix to ensure monotonicity of (args[i] - i)
      @  requires (\forall int i; 0 <= i && i + 1 < array; args[i] < args[i+1]);
      @
      @  ensures -1 <= \result && \result < array;
      @  ensures (\result == -1) <==> (\forall int i; 0 <= i && i < array; args[i] != i);
      @  ensures (0 <= \result && \result < array) ==> (args[\result] == \result);
      @  ensures (\forall int i; 0 <= i && i < args.length; args[i] == \old(args[i]));
      @*/
    /*@ spec_public @*/ public static int findFixedPoint(int[] args, int array) {
        int ret = 0;
        int stop = array - 1;
        //@ maintaining 0 <= ret && ret <= array && -1 <= stop && stop < array;
        //@ maintaining (\forall int k; 0 <= k && k < ret; args[k] < k);
        //@ maintaining (\forall int k; stop < k && k < array; args[k] > k);
        //@ decreases stop - ret + 1;
        while (ret <= stop) {
            int i = ret + (stop - ret) / 2;
            if (args[i] == i) {
                return i;
            } else if (args[i] < i) {
                ret = i + 1;
            } else {
                stop = i - 1;
            }
        }
        return -1;
    }
}