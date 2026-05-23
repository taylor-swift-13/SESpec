class SVCOMP_linear_0149__232 {
    /*@
      @ // original parameter was unsigned; require non-negativity to reflect that
      @ requires y >= 0;
      @ // no meaningful postcondition can mention the local x (it is out of scope), so keep a trivial ensures
      @ ensures true;
      @*/
    static void foo232(int y) {

        int x;

        x = 2;

        /*@
          @ // x is initialized to 2 and stays at least 2 while the loop executes
          @ maintaining x >= 2;
          @ // x is always non-negative
          @ maintaining x >= 0;
          @*/
        while (x < y) {
            if (x < y / x) {
                x *= x;
            }
            else {
                x++;
            }
        }

    }
}