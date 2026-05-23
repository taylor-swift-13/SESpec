class instanceof1 {
  //@ ensures \result <==> args != null;
  /*@ spec_public @*/ public static boolean f(String[] args) {
    return args instanceof Object;
  }

  //@ ensures true;
  /*@ spec_public @*/ public static void main(String[] args) {
    f(args);
  }
}