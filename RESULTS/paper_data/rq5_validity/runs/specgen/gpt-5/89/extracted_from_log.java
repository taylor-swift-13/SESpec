class Sespec0089 {
    //@ ensures k == \old(k);
    //@ assignable \nothing;
    static /*@ spec_public @*/ void foo89(int k) {
        int y = 0;
        int x = 0;
        int c = 0;
        //@ maintaining c >= 0 && y == c && x == (\sum int i; 1 <= i && i <= c; i*i*i*i*i);
        //@ decreases (k <= c ? 0 : k - c);
        while (c < k) {
            c = c + 1;
            y = y + 1;
            x = y * y * y * y * y + x;
        }
    }
}