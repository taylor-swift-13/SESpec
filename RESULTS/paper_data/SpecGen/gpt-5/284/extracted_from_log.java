import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

/*@ spec_public @*/ class GetGcd {

    /*@
      @ requires arr != null && arr.length >= 1;
      @ ensures 0 <= \result && \result <= (arr[0] >= 0 ? arr[0] : 0);
      @ ensures (\forall int k; 0 <= k && k < arr.length; arr[k] == \old(arr[k]));
      @ ensures arr.length == 1 ==> \result == 0;
      @*/
    /*@ spec_public @*/ public static int getGcd(int[] arr) {
        int result = 0;
        int min = arr[0];
        //@ maintaining 1 <= i && i <= arr.length;
        //@ maintaining (\forall int t; 0 <= t && t < i; min <= arr[t]);
        //@ maintaining 0 <= result && result <= (arr[0] >= 0 ? arr[0] : 0);
        //@ decreases arr.length - i;
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