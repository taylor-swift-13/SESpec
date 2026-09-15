class Sespec0031 {
    //@ ensures i == 0 ==> \result == 0;
    //@ ensures i != 0 ==> \result == 1;
    /*@ spec_public @*/ static int foo31(int i) {
        if (i == 0) return 0;
        int j = 10 / i;
        return 1;
    }
}