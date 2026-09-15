class SVCOMP_linear_0290__75 {
    //@ ensures \result == 0; 
    static int unknown() {
        return 0;
    }

    //@ requires true;
    //@ ensures true;
    static void foo75(int y, int x1, int x2, int x3) {
        int c = 0;
        int z = 36 * y;

        //@ maintaining c >= 0 && c <= 36;
        //@ maintaining z == 36 * y + c;
        //@ decreases unknown();
        while (unknown() != 0) {
            if (c < 36) {
                z = z + 1;
                c = c + 1;
            }
        }
    }
}