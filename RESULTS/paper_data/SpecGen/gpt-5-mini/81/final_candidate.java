class SVCOMP_linear_0290__75 {
    /*@ public normal_behavior
      @ ensures \result == 0;
      @*/
    static int unknown() {
        return 0;
    }

    /*@ public normal_behavior
      @ ensures true;
      @*/
    static void foo75(int y,int x1,int x2,int x3) {
        int c = 0;
        int z = 36 * y;

        /*@ 
          @ maintaining 0 <= c && c <= 36;
          @ maintaining z == 36*y + c;
          @ decreases 36 - c;
          @*/
        while (unknown() != 0) {

            if ( c < 36 )
            {
                z  = z + 1;
                c  = c + 1;
            }
        }

    }
}