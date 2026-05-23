class SVCOMP_linear_0149__232 {
    static void foo232(int y) {
        int x;

        x = 2;

 
        //@ maintaining (\forall int k; 2 <= k && k < x; k * k <= y || k + 1 <= y);
        //@ decreases y - x;
        while (x < y) {
            if (x < y / x) {
                x *= x;
            } else {
                x++;
            }
        }
    }
}
