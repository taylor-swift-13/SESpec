class Sespec0021 {
    /*@
      @ requires s != null && s.length >= 2;
      @ ensures (s[0] == 't' && s[1] == 'e') ==> \result == 1;
      @ ensures !(s[0] == 't' && s[1] == 'e') ==> \result == 0;
      @ ensures 0 <= \result && \result <= 1;
      @ assignable \nothing;
      @*/
    /*@ pure @*/ static int starts_with_te(char[] s) {
        return (s[0] == 't' && s[1] == 'e') ? 1 : 0;
    }

    /*@
      @ requires args != null;
      @ requires args.length < 4 || (\forall int j; 0 <= j && j < 4; args[j] != null && args[j].length >= 2);
      @ ensures args.length < 4 ==> (\result == 0);
      @ ensures \result == 1 ==> (args.length >= 4 && (\exists int j; 0 <= j && j < 4; starts_with_te(args[j]) != 0 && (\forall int k; 0 <= k && k < 4 && k != j; starts_with_te(args[k]) == 0)));
      @ ensures 0 <= \result && \result <= 1;
      @ assignable \nothing;
      @*/
    static int foo21(char[][] args) {
        if (args.length < 4) return 0;
        int i = 0;
        /*@
          @ maintaining 0 <= j && j <= 4;
          @ maintaining 0 <= i && i <= j;
          @ decreases 4 - j;
          @*/
        for (int j = 0; j < 4; j++) {
            if (starts_with_te(args[j]) != 0) ++i;
        }
        return (i == 1) ? 1 : 0;
    }
}