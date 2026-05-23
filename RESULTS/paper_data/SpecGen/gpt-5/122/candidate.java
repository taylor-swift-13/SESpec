class Sespec0122 {
    static int foo122(char[] s) {
        int n = s.length;
        for (int i = 0; i < s.length; i++) {
            if (s[i] != s[n - 1 - i]) {
                return 0;
            }
        }
        return 1;
    }
}
