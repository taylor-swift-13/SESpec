public class boundcheck30 {

  /*@ spec_public @*/ private static boolean recursion(int i) {
    //@ requires true;
 
 
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