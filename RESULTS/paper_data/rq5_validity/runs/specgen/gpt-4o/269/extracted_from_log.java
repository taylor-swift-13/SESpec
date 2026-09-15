import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

    //@ requires dim >= 0 && w > 0;
 
 
    //@ ensures dim == 1 ==> \result == w;
 
 
      @     div.length == dim + 1 &&
      @     div[0] == 1 &&
      @     div[1] == w &&
      @     div[2] == (w * w) % 1000000007 &&
      @     (\forall int d; 3 <= d && d <= dim;
      @         div[d] == ((w - 1) * (div[d - 1] + div[d - 2])) % 1000000007) &&
      @     \result == div[dim]);
      @*/
    public static int countNoOfWays(int dim, int w) {
        int mod = 1000000007;
        int[] div = new int[dim + 1];
        div[0] = 1;
        if (dim >= 1) div[1] = w;
        if (dim >= 2) div[2] = (w * w) % mod;

        for (int d = 3; d <= dim; d++) {
            //@ assume d - 1 >= 0 && d - 2 >= 0;
            div[d] = ((w - 1) * (div[d - 1] + div[d - 2])) % mod;
        }
        return div[dim];
    }
}