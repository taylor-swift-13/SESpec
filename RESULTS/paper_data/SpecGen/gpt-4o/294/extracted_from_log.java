import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

    //@ requires p >= 0;
    //@ ensures \result == (\let int[] pellSeq = (\new int[p + 1]); pellSeq[0] == 0 && pellSeq[1] == 1 && (\forall int i; 2 <= i && i <= p; pellSeq[i] == (2 * pellSeq[i - 1] + pellSeq[i - 2]) % 1000000000) && pellSeq[p] == \result);
    public static int getPell(int p) {
        //@ spec_public
        int[] arr = new int[p + 1];
        arr[0] = 0;
        arr[1] = 1;
        //@ maintaining 2 <= count && count <= p + 1;
        //@ maintaining (\forall int i; 2 <= i && i < count; arr[i] == (2 * arr[i - 1] + arr[i - 2]) % 1000000000);
        //@ decreases p - count;
        for (int count = 2; count <= p; count++) {
            arr[count] = (2 * arr[count - 1]
                    + arr[count - 2]) % 1000000000;
        }
        return arr[p];
    }
}