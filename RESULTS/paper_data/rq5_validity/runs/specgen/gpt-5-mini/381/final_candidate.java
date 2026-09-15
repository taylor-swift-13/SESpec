import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class NumCommDiv {

    /*@ public normal_behavior
 
 
      @*/
    public static int numCommDiv(int x, int y) {
        int count = 0;
        /*@ 
          @ maintaining 1 <= i;
 
          @ decreases x - i + 1;
          @*/
        for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
        return count;
    }
}
