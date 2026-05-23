class Sespec0087 {
    //@ requires k >= 0;
    //@ assignable \nothing;
    //@ ensures k == \old(k);
    /*@ spec_public @*/ static void foo87(int k) {
        int y = 0;
        int x = 0;
        int c = 0;
        //@ maintaining 0 <= c && c <= k;
        //@ maintaining y == c;
        //@ maintaining x == (\sum int i; 1 <= i && i <= c; i*i*i);
        //@ decreases k - c;
        while (c < k) {
            c = c + 1;
            y = y + 1;
            x = y * y * y + x;
        }
    }
}