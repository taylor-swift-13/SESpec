class SVCOMP_linear_0287__72 {
    /*@ spec_public @*/ static int unknown() {
        return 0;
    }

    //@ requires true;
    //@ ensures true;
    static void foo72(int y) {
        int c = 0;
        int z = 36 * y;

        //@ maintaining c >= 0 && c <= 36;
        //@ maintaining z == 36 * y + c;
        //@ maintaining \exists int i; 0 <= i && i <= c; z == 36 * y + i;  
 
        while (unknown() != 0) {
            if (c < 36) {
                z = z + 1;
                c = c + 1;
            }
        }
    }
}