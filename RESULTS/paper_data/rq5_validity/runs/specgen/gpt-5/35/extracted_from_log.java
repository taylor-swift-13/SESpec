public class bitwise1 {
  /*@ spec_public @*/ static char c;

  //@ ensures c == (char)(input * 2 + 1);
  //@ ensures \result;
  public static boolean fun(int input) {
    c = (char) (input * 2 + 1);
    int i = (c | 2);
    return (i & 3) == 3;
  }
}