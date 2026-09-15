public class boundcheck30 {

  //@ ensures \result <==> i >= 0;
  //@ assignable \nothing;
  /*@ spec_public @*/ private static boolean recursion(int i) {
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