class SVCOMP_linear_0287__72 {
    //@ ensures \result == 0;
    static int unknown() {
        return 0;
    }

    //@ ensures true;
    static void foo72(int y) {
        int c = 0;
        int z = 36 * y;

        //@ maintaining true;
        while (unknown() != 0) {

            if ( c < 36 )
            {
                z  = z + 1;
                c  = c + 1;
            }
        }

    }
}