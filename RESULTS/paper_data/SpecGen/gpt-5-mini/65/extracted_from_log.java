class SVCOMP_linear_0183__263 {
    //@ requires k >= 0;
    //@ ensures true;
    static void foo263(int k) {

    int n;
    int i;

    n = 0;
    i = 0;

    //@ maintaining 0 <= i && i <= 2 * k;
    //@ maintaining n == (i + 1) / 2;
    //@ decreases 2 * k - i;
    while (i < 2 * k) {
        if(i % 2 == 0){
            n = n + 1;
        }
        i = i + 1;
    }

    }
}