class Sespec0123 {
    //@ requires pat != null && txt != null;
    //@ ensures (\result == 1) <==> (pat.length() <= txt.length() && (\forall int k; 0 <= k && k < pat.length(); pat.charAt(k) == txt.charAt(k)));
    //@ ensures \result == 0 || \result == 1;
    /*@ spec_public @*/ static int foo123(String pat, String txt) {
        int i = 0;
        //@ maintaining 0 <= i && i <= pat.length();
        //@ maintaining i <= txt.length();
        //@ maintaining (\forall int k; 0 <= k && k < i; pat.charAt(k) == txt.charAt(k));
        //@ decreases pat.length() - i;
        while (i < ((int) pat.length())) {
            if (i >= ((int) txt.length()) || pat.charAt(i) != txt.charAt(i))
                return 0;
            i = i + 1;
        }
        return 1;
    }
}