class SVCOMP_linear_0086__176 {
    //@ requires k >= 0;
    //@ ensures true; // No specific postcondition is required for this method.
    static void foo176(int i, int j, int k) {

        int n;
        int b;

        n = 0;
        b = 1;

        //@ maintaining 0 <= n && n <= 2 * k;
        //@ maintaining b == 0 || b == 1;
        //@ maintaining n % 2 == 0 ==> b == 1;
        //@ maintaining n % 2 == 1 ==> b == 0;
        //@ decreases (2 * k) - n;
        while (n < (2 * k)) {
            n = n + 1;
            if (b == 1) {
                b = 0;
                i = i + 1;
            } else {
                b = 1;
                j = j + 1;
            }
        }
    }
}