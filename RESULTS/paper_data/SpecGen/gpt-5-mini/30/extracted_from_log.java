class Main {
  /*@ spec_public @*/
  //@ ensures \result;
  public static boolean f() {
    int i[] = new int[10];
    return i[3] == 0;
  }
}