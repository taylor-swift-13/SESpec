class Sespec0088 {
    //@ ensures k == \old(k);
    //@ assignable \nothing;
    static /*@ spec_public @*/ void foo88(int k) {
        int y = 0;
        int x = 0;
        int c = 0;
        //@ maintaining 0 <= c && y == c && x >= 0 && (k >= 0 ==> c <= k);
        //@ decreases (c < k) ? (k - c) : 0;
        while (c < k) {
            c = c + 1;
            y = y + 1;
            x = y * y * y * y + x;
        }
    }
}