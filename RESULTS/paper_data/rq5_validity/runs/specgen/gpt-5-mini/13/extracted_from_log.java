class recursion2 {
  /*@ public normal_behavior
      ensures \result <==> recursion_test(0) == 10;
    @*/
  /*@ pure @*/
  /*@ spec_public @*/
  public static boolean f() {
    return recursion_test(0) == 10;
  }

  /*@ public normal_behavior
      ensures depth >= 10 ==> \result == 0;
      ensures depth < 10  ==> \result == 10 - depth;
      ensures \result >= 0;
    @*/
  /*@ pure @*/
  /*@ spec_public @*/
  static int recursion_test(int depth) {
    if (depth < 10) return recursion_test(depth + 1) + 1;
    else return 0;
  }
}