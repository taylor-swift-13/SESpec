class recursion2 {
  //@ ensures \result == true;
  public static boolean f() {
    return recursion_test(0) == 10;
  }

  //@ requires depth >= 0;
  //@ ensures \result == (depth <= 10 ? 10 - depth : 0);
  static int recursion_test(int depth) {
    if (depth < 10) return recursion_test(depth + 1) + 1;
    else return 0;
  }
}