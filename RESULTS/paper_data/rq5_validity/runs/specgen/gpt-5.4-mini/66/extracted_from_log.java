class SVCOMP_linear_0206__284 {
    //@ ensures true;
    static void foo284(int y) {

        int x;

        x = 4 * y;

        //@ maintaining x == 4 * y;
        //@ decreases x;
        while (x > 0) {
            x -= 4;
            y--;
        }

    }
}