class Sespec0090 {
    //@ ensures (\exists int q, r; q >= 0 && r >= 0 && (y > 0 ==> r < y) && x <= y * q + r);
    static void foo90(int x, int y) {
        int q = 0;
        int r = 0;
        //@ maintaining q >= 0 && r >= 0 && (y > 0 ==> r < y);
        //@ maintaining x > y * q + r;
        //@ decreases x - (y * q + r);
        while (x > y * q + r) {
            if (r == y - 1) {
                r = 0;
                q += 1;
            } else {
                r += 1;
            }
        }
    }
}