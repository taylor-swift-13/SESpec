class SVCOMP_linear_0206__284 {
    /*@ 
 
 
      @*/
    static void foo284(int y) {

        int x;

        x = 4 * y;

        //@ maintaining x == 4 * y;
        //@ maintaining x % 4 == 0;
        //@ decreases (y >= 0 ? y : 0);
        while (x > 0) {
            x -= 4;
            y--;
        }

    }
}