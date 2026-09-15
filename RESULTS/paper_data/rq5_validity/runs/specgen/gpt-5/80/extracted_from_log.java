class SVCOMP_linear_0290__75 {
  //@ ensures \result == 0;
  /*@ spec_public @*/ static int unknown() {
    return 0;
  }

  //@ ensures true;
  /*@ spec_public @*/ static void foo75(int y,int x1,int x2,int x3) {
    int c = 0;
    int z = 36 * y;

    //@ maintaining 0 <= c && c <= 36;
    //@ maintaining z == 36 * y + c;
    //@ maintaining 36 * y <= z && z <= 36 * y + 36;
    while (unknown() != 0) {

      if ( c < 36 )
      {
        z  = z + 1;
        c  = c + 1;
      }
    }

  }
}