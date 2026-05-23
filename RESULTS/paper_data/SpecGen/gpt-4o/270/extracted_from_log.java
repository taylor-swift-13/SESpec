import java.io.*;

class CountNoOfWays {

    //@ requires count >= 0 && m > 0;
 
    //@ ensures (count == 0 ==> \result == 1);
    //@ ensures (count == 1 ==> \result == m);
    //@ ensures (count == 2 ==> \result == m * m);
 
    public static int countNoOfWays(int count, int m) {
        int w = 1000000007;

        if (count == 0) return 1;
        if (count == 1) return m;
        if (count == 2) return m * m;

        int prev2 = 1; // div[0]
        int prev1 = m; // div[1]
        int current = m * m; // div[2]

        for (int d = 3; d <= count; d++) {
            int next = ((m - 1) * (prev1 + prev2)) % w;
            prev2 = prev1;
            prev1 = current;
            current = next;
        }
        return current;
    }

    //@ requires count >= 3 && m > 0;
    //@ ensures \result >= 0;
    //@ pure
    /*@ spec_public @*/ private static int computeWaysSpec(int count, int m) {
        int w = 1000000007;

        int prev2 = 1; // div[0]
        int prev1 = m; // div[1]
        int current = m * m; // div[2]

        //@ maintaining 3 <= d && d <= count + 1;
        //@ maintaining prev2 >= 0 && prev1 >= 0 && current >= 0;
        //@ decreases count - d + 1;
        for (int d = 3; d <= count; d++) {
            int next = ((m - 1) * (prev1 + prev2)) % w;
            prev2 = prev1;
            prev1 = current;
            current = next;
        }
        return current;
    }
}