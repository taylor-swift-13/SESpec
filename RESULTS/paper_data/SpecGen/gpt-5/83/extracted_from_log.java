class Sespec0083 {
    /*@
      @ assignable \nothing;
      @ ensures z == \old(z) && k == \old(k) && a == \old(a);
      @*/
    static void foo83(int z, int k, int a) {
        int x = a;
        int y = 1;
        int c = 1;
        //@ maintaining 1 <= c;
        //@ decreases k - c;
        while (c < k) {
            c = c + 1;
            x = x * z + a;
            y = y * z;
        }
    }
}