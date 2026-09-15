class recursion2 {
 
  public static boolean f() {
    return recursion_test(0) == 10;
  }

  //@ requires depth >= 0;
 
  /*@ spec_public @*/ static int recursion_test(int depth) {
    if (depth < 10) return recursion_test(depth + 1) + 1;
    else return 0;
  }
}