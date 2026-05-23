class Sespec0125 {
    //@ requires pat != null && txt != null;
    //@ assignable \nothing;
    //@ ensures 0 <= \result && \result <= 1;
    //@ ensures \result == 1 <==> (pat.length <= txt.length && (\forall int k; 0 <= k && k < pat.length; pat[k] == txt[txt.length - pat.length + k]));
    //@ ensures \result == 0 ==> (pat.length > txt.length || (pat.length <= txt.length && (\exists int k; 0 <= k && k < pat.length; pat[k] != txt[txt.length - pat.length + k])));
    static /*@ spec_public @*/ int foo125(char[] pat, char[] txt) {
        int i = pat.length - 1;
        //@ maintaining -1 <= i && i < pat.length;
        //@ maintaining (\forall int k; i < k && k < pat.length; (0 <= txt.length - pat.length + k && txt.length - pat.length + k < txt.length) ==> pat[k] == txt[txt.length - pat.length + k]);
        //@ decreases i + 1;
        while (i >= 0) {
            int j = i - pat.length + txt.length;
            if (j < 0 || pat[i] != txt[j]) {
                return 0;
            }
            i = i - 1;
        }
        return 1;
    }
}