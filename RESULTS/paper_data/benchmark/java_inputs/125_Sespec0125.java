class Sespec0125 {
    static int foo125(char[] pat, char[] txt) {
        int i = pat.length - 1;
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
