class instanceof1 {
  /*@ public normal_behavior
        ensures \result == (args instanceof Object);
    @*/
  public static boolean f(String[] args) {
    return args instanceof Object;
  }

  /*@ public normal_behavior
        ensures \true;
    @*/
  public static void main(String[] args) {
    f(args);
  }
}