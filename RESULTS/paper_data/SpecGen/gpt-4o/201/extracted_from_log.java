public class CountWays {

    /**
     * Counts the number of ways to tile a 2xN board using 2x1 dominoes and L-shaped trominoes.
     *
     * @param n The size of the board (must be non-negative).
     * @return The number of ways to tile the board.
     */
    //@ requires n >= 0;
 
    //@ ensures n == 0 ==> \result == 1;
    //@ ensures n == 1 ==> \result == 0;
    public static int countWays(int n) {
        if (n == 0) {
            return 1; // Base case: 1 way to tile a 2x0 board (do nothing).
        }
        if (n == 1) {
            return 0; // Base case: No way to tile a 2x1 board with given pieces.
        }

        int[] A = new int[n + 1];
        int[] B = new int[n + 1];

        A[0] = 1;
        A[1] = 0;
        B[0] = 0;
        B[1] = 1;

        for (int i = 2; i <= n; i++) {
            //@ assume i - 2 >= 0 && i - 1 >= 0;
            A[i] = A[i - 2] + 2 * B[i - 1];
            //@ assume i - 1 >= 0 && i - 2 >= 0;
            B[i] = A[i - 1] + B[i - 2];
        }

        return A[n];
    }
}