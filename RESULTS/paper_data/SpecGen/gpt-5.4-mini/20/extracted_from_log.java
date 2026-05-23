public class StringMiscellaneous03 {
  //@ requires s1 != null && s2 != null;
  //@ requires s1.length() == s2.length();
 
  public static boolean f(String s1, String s2) {
    int i = 0;
    //@ maintaining 0 <= i && i <= s1.length();
 
    //@ decreases s1.length() - i;
    for (int count = s1.length() - 1; count >= 0; count--) {
      if (s1.charAt(count) == s2.charAt(i))
        return false;
      ++i;
    }
    return true;
  }
}