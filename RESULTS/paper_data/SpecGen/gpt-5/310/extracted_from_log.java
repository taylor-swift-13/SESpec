import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class SqrtRoot {

    /*@ ensures (\result == -1) <==> (num < 0);
      @ ensures (0 <= num) ==> (
      @            \result >= 0
      @         && ((long)\result) * ((long)\result) <= (long) num
      @         && ((long)(\result + 1)) * ((long)(\result + 1)) > (long) num
      @      );
      @*/
    public static int sqrtRoot(int num) {
        if (num < 0) {
            return -1;
        }
        int left = 0;
        int right = num;
        //@ maintaining 0 <= left && -1 <= right && right <= num && left <= right + 1;
        //@ maintaining (\forall int i; 0 <= i && i < left; ((long)i) * ((long)i) <= (long) num);
        //@ maintaining (\forall int i; right < i && i <= num; ((long)i) * ((long)i) > (long) num);
        //@ decreases right - left + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid * mid == num) {
                return mid;
            } else if (mid * mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
}