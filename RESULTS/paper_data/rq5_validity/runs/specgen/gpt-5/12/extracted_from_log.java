public class boundcheck30 {

  //@ assignable \nothing;
  //@ ensures \result <==> i >= 0;
  private /*@ spec_public @*/ static boolean recursion(int i) {
    if (i == 0) {
      return true;
    }
    if (i > 0) {
      return recursion(i - 1);
    }
    if (i < 0) {
      return false;
    }
    return true;
  }

}