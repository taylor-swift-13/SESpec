class Sespec0033 {
    //@ ensures denom == 0 ==> \result == 0;
    //@ ensures denom != 0 ==> \result == 1;
    static int foo33(int denom) {
        if (denom == 0) return 0;
        int j = 10 / denom;
        return 1;
    }
}