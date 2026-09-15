class SVCOMP_linear_0172__253 {
    //@ ensures \result == 0;
    static int unknown() {
        return 0;
    }

    //@ ensures true;
    static void foo253() {

        int i;
        int j;
        int a;
        int b;

        a = 0;
        b = 0;
        j = 1;
        i = 1;

        //@ maintaining a >= 0;
        //@ maintaining b == 0;
        //@ maintaining i >= 1;
        //@ maintaining j >= 1;
        //@ decreases 0;
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