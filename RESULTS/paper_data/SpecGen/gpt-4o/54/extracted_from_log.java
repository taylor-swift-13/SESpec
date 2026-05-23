class SVCOMP_linear_0144__228 {
    static void foo228() {

        int x;
        int y;

        x = 0;
        y = 0; // Initialize y to avoid uninitialized variable error

        //@ maintaining 0 <= x && x - 1 <= 99;  
        //@ maintaining (\forall int k; 0 <= k && k < x; k % 2 == 0 || k % 2 == 1);
        //@ decreases 99 - x;
        while (x < 99) {
            if (y % 2 == 0) {
                x = x + 2;
            } else {
                x = x + 1;
            }
        }
    }
}