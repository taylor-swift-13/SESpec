class SVCOMP_linear_0092__181 {
    //@ requires k >= 0;
 
    static void foo181(int i, int j, int k) {

        int n;
        int b;

        n = 0;
        b = 0;

        //@ maintaining 0 <= n && n <= 2 * k;
        //@ maintaining (n % 2 == 0 ==> b == 0) && (n % 2 == 1 ==> b == 1);
        //@ maintaining i == \old(i) + (n / 2);
 
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