class SVCOMP_linear_0161__243 {
    /*@ spec_public @*/ static int unknown() {
        return 0;
    }

    static void foo243() {
        int x = 0; // Initialize x to avoid "might not have been initialized" error
        int y = 1; // Initialize y to 1 as per the original code

        //@ maintaining true; // Since the loop condition depends on unknown(), which has no defined behavior, we cannot assert specific properties about the loop.
        while (unknown() != 0) {
            if (x % 3 == 1) {
                x = x + 2;
                y = 0;
            } else {
                if (x % 3 == 2) {
                    x = x + 1;
                    y = 0;
                } else {
                    if (unknown() != 0) {
                        x = x + 4;
                        y = 1;
                    } else {
                        x = x + 5;
                        y = 1;
                    }
                }
            }
        }
    }
}