class recursion2 {
  //@ ensures \result;
  //@ assignable \nothing;
  /*@ spec_public @*/ public static boolean f() {
    return recursion_test(0) == 10;
  }

  //@ ensures \old(depth) < 10 ==> \result == 10 - \old(depth);
  //@ ensures \old(depth) >= 10 ==> \result == 0;
  //@ assignable \nothing;
  /*@ spec_public @*/ static int recursion_test(int depth) {
    if (depth < 10) return recursion_test(depth + 1) + 1;
    else return 0;
  }
}