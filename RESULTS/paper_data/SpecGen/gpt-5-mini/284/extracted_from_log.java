import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetGcd {

    /*@ public normal_behavior
      @   requires arr != null && arr.length > 0;
      @ 
      @   // The result is the maximum among the prefix-minima that were
      @   // witnessed by a later element greater than that prefix-minimum.
      @   // More precisely: for every index j with 1 <= j < arr.length, if
      @   // arr[j] > (\min int t; 0 <= t && t < j; arr[t]) then \result is
      @   // greater-or-equal than that prefix-minimum.
      @   ensures (\forall int j; 1 <= j && j < arr.length &&
      @               arr[j] > (\min int t; 0 <= t && t < j; arr[t])
      @            ==> \result >= (\min int t; 0 <= t && t < j; arr[t]));
      @
      @   // If there exists such a j, then \result equals one of those
      @   // prefix-minima (in fact the maximum of them); otherwise \result == 0.
      @   ensures ((\exists int j; 1 <= j && j < arr.length &&
      @               arr[j] > (\min int t; 0 <= t && t < j; arr[t]))
      @            ==> (\exists int j; 1 <= j && j < arr.length &&
      @                      arr[j] > (\min int t; 0 <= t && t < j; arr[t]) &&
      @                      \result == (\min int t; 0 <= t && t < j; arr[t])));
 
      @               !(arr[j] > (\min int t; 0 <= t && t < j; arr[t])))
      @           ==> \result == 0;
      @*/
    public static int getGcd(int[] arr) {
        int result = 0;
        int min = arr[0];
        /*@ 
          @   // Loop invariant: at the start of the iteration with index i
          @   // (1 <= i <= arr.length) 'min' is the minimum of arr[0..i-1]
          @   // and 'result' is the maximum among the prefix-minima witnessed
          @   // so far (or 0 if none).
          @   maintaining 1 <= i && i <= arr.length;
 
          @   maintaining (\forall int j; 1 <= j && j < i &&
          @                 arr[j] > (\min int t; 0 <= t && t < j; arr[t])
          @              ==> result >= (\min int t; 0 <= t && t < j; arr[t]));
          @   maintaining (
          @       ((\exists int j; 1 <= j && j < i &&
          @            arr[j] > (\min int t; 0 <= t && t < j; arr[t])))
          @        ==> (\exists int j; 1 <= j && j < i &&
          @                   arr[j] > (\min int t; 0 <= t && t < j; arr[t]) &&
          @                   result == (\min int t; 0 <= t && t < j; arr[t]))
          @   ) || (
          @       (\forall int j; 1 <= j && j < i ==>
          @            !(arr[j] > (\min int t; 0 <= t && t < j; arr[t])))
          @       && result == 0
          @   );
          @   decreases arr.length - i;
          @*/
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > min) {
                result = result > min ? result : min;
            } else {
                min = arr[i];
            }
        }
        return result;
    }
}