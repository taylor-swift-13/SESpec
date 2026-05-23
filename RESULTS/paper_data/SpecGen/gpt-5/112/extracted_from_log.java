class Sespec0112 {
    //@ requires str != null;
    //@ requires (\forall int t; 0 <= t && t < str.length; str[t] == '\0' || ('a' <= str[t] && str[t] <= 'z'));
    //@ assignable \nothing;
    //@ ensures \result == 0 || \result == 1;
    /*@ spec_public @*/ static int foo112(char[] str) {
        int len = 0;
        //@ maintaining 0 <= len && len <= str.length;
        //@ maintaining (\forall int t; 0 <= t && t < len; str[t] != '\0');
        //@ decreases str.length - len;
        while (len < str.length && str[len] != '\0') {
            len++;
        }
        //@ assert (\forall int t; 0 <= t && t < len; str[t] != '\0');
        if (len > 26) {
            return 0;
        }
        int num = 0;
        //@ maintaining 0 <= i && i <= len;
        //@ decreases len - i;
        for (int i = 0; i < len; i++) {
            char c = str[i];
            //@ assert c != '\0';
            //@ assert 'a' <= c && c <= 'z';
            int index = c - 'a';
            //@ assert 0 <= index && index < 26;
            if ((num & (1 << index)) != 0) {
                return 0;
            } else {
                num |= (1 << index);
            }
        }
        return 1;
    }
}