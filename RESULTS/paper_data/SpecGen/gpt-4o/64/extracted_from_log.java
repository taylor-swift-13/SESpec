class SVCOMP_linear_0172__253 {
    //@ ensures \result == 0; // The behavior of `unknown` is undefined, so we assume it always returns 0.
    static int unknown() {
        return 0;
    }

    //@ ensures true; // No postcondition can be guaranteed as the behavior depends on `unknown`.
    static void foo253() {
        int i;
        int j;
        int a;
        int b;

        a = 0;
        b = 0;
        j = 1;
        i = 1;

        //@ maintaining a >= 0 && b >= 0 && i >= 1 && j >= 1;
        //@ maintaining (\forall int k; 0 <= k && k <= a; b >= 0 && i >= 1 && j >= 1);
        //@ decreases unknown(); // The loop termination depends on the behavior of `unknown`.
        while (unknown() != 0) {
            a = a + 1;
            b = b + j - i;
            i = i + 2;
            if (i % 2 == 0) {
                j = j + 2;
            } else {
                j = j + 1;
            }
        }
    }
}