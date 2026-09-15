import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

    /*@ public normal_behavior
      @ requires true;
 
 
 
 
      @*/
    /*@ spec_public @*/ public static int findDivisor(int x, int y) {
        if (y < 0) {
            y = -y;
        }
        int count = 0;
        /*@ 
          @ // loop invariants: index i runs from 1 to y, count is non-negative and bounded by y
          @ maintaining 1 <= i && i <= y + 1;
 
          @ decreases y + 1 - i;
          @*/
        for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
    }
}
