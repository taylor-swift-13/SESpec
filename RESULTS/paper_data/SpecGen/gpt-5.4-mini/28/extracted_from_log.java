class instanceof1 {
  //@ requires args != null;
 
  public static boolean f(String[] args) {
    return args instanceof Object;
  }

  //@ requires args != null;
  //@ ensures true;
  public static void main(String[] args) {
    f(args);
  }
}