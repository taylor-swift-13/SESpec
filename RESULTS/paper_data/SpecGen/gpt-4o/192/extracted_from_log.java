import java.io.*;
import java.lang.*;
import java.util.*;

class CountWays {

    //@ requires count >= 0;
    //@ ensures \result >= 0;
    public static int countWays(int count) {
        if (count < 0) {
            throw new IllegalArgumentException("Count must be non-negative");
        }

        int[] w = new int[count + 1];
        int[] C = new int[count + 1];
        w[0] = 1;
        C[0] = 0;

        //@ loop_invariant 1 <= index && index <= count + 1;
        //@ loop_invariant (\forall int i; 0 <= i && i < index; w[i] >= 0 && C[i] >= 0);
        //@ decreases count - index + 1;
        for (int index = 1; index <= count; index++) {
            w[index] = (index - 2 >= 0 ? w[index - 2] : 0) + 2 * (index - 1 >= 0 ? C[index - 1] : 0);
            C[index] = (index - 1 >= 0 ? w[index - 1] : 0) + (index - 2 >= 0 ? C[index - 2] : 0);
        }

        return w[count];
    }
}