class SVCOMP_linear_0171__252 {
    //@ ensures \result == 0;
    /*@ spec_public @*/ static int unknown() {
        return 0;
    }

    //@ ensures true;
    /*@ spec_public @*/ static void foo252() {

        int i;
        int j;
        int a;
        int b;

        a = 0;
        b = 0;
        j = 1;
        i = 0;

        //@ maintaining a == b && i % 2 == 0 && j == i + 1;
        while (unknown() != 0) {
            a = a + 1;
            b = b + j - i;
            i = i + 2;
            if (i % 2 == 0){
                j = j + 2;
            }
            else{
                j = j + 1;
            }
        }

    }
}