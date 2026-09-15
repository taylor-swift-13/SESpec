class Sespec0327 {
    //@ requires 0 <= n && n <= 12;
    //@ ensures 1 <= \result && \result <= 9;
    //@ ensures n <= 1 ==> \result == 1;
    /*@ spec_public @*/ static int foo327(int n) {
        int fact = 1;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining fact >= 1;
        //@ decreases n - i + 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int foo327 = 0;
        //@ maintaining fact >= 0;
        //@ maintaining 0 <= foo327 && foo327 <= 9;
        //@ decreases fact;
        while (fact > 0) {
            foo327 = fact % 10;
            fact /= 10;
        }
        return foo327;
    }
}