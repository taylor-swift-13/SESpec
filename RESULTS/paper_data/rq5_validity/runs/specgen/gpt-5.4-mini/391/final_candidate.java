import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class NextPerfectSquare {

    /*@ requires true;
 
      @ ensures (\forall int j; j >= 0 && j * j <= n; j * j < \result);
      @*/
    public static int nextPerfectSquare(int n) {
        int i = 1;
        int square = 1;
        /*@ maintaining i >= 1;
          @ maintaining square >= 1;
 
 
 
          @*/
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
    }
}
