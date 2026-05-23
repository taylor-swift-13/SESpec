class Sespec0082 {
    /*@ ensures k == \old(k) && z == \old(z); @*/
    static void foo82(int z, int k) {
        int x = 1;
        int y = 1;
        int c = 1;
        /*@
          @ maintaining c >= 1;
          @ maintaining (k <= 1 ==> c == 1);
          @ maintaining (k > 1 ==> c >= 1 && c <= k);
          @ decreases k - c;
          @*/
        while (c < k) {
            c = c + 1;
            x = x * z + 1;
            y = y * z;
        }
    }
}