public class StringMiscellaneous03 {
  //@ requires s1 != null && s2 != null && s2.length() >= s1.length();
  //@ ensures \result <==> (\forall int k; 0 <= k && k < s1.length(); s1.charAt(k) != s2.charAt(s1.length() - 1 - k));
  //@ ensures !\result <==> (\exists int k; 0 <= k && k < s1.length(); s1.charAt(k) == s2.charAt(s1.length() - 1 - k));
  public static boolean f(String s1, String s2) {
    int i = 0;
    //@ maintaining 0 <= i && i <= s1.length();
    //@ maintaining -1 <= count && count < s1.length();
    //@ maintaining i == s1.length() - 1 - count;
    //@ maintaining (\forall int k; count < k && k < s1.length(); s1.charAt(k) != s2.charAt(s1.length() - 1 - k));
    //@ decreases count + 1;
    for (int count = s1.length() - 1; count >= 0; count--) {
      if (s1.charAt(count) == s2.charAt(i))
        return false;
      ++i;
    }
    return true;
  }
}