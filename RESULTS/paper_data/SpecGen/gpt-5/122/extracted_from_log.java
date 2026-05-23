class Sespec0122 {
    /*@ requires s != null;
      @ ensures (\result == 1) <==> (\forall int i; 0 <= i && i < s.length; s[i] == s[s.length - 1 - i]);
      @ ensures \result == 0 || \result == 1;
      @*/
    static int foo122(char[] s) {
        int n = s.length;
        //@ maintaining 0 <= i && i <= s.length;
        //@ maintaining n == s.length;
        //@ maintaining (\forall int j; 0 <= j && j < i; s[j] == s[n - 1 - j]);
        //@ decreases s.length - i;
        for (int i = 0; i < s.length; i++) {
            if (s[i] != s[n - 1 - i]) {
                return 0;
            }
        }
        return 1;
    }
}