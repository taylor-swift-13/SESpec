class Sespec0004 {
    /*@ spec_public @*/ static int counter;

    /*@ requires 1 <= n && n <= 31;
      @ ensures \result == ((n == 31) ? Integer.MAX_VALUE : ((1 << n) - 1));
      @*/
    static int foo25_helper1_c4(int n) {
        if (n == 1) return 1;
        return 2 * foo25_helper1_c4(n - 1) + 1;
    }

    /*@ requires n >= 0 && n <= 31;
      @ requires counter <= Integer.MAX_VALUE - ((n == 31) ? Integer.MAX_VALUE : ((1 << n) - 1));
      @ ensures counter == \old(counter) + ((n == 31) ? Integer.MAX_VALUE : ((1 << n) - 1));
      @ ensures from == \old(from) && to == \old(to) && via == \old(via);
      @*/
    static void foo4(int n, int from, int to, int via) {
        if (n == 0) return;
        counter++;
        foo4(n - 1, from, via, to);
        foo4(n - 1, via, to, from);
    }
}