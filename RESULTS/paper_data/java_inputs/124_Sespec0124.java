class Sespec0124 {
    static int strlen(char[] s) {
        int len = 0;
        while (len < s.length && s[len] != '\0') {
            len++;
        }
        return len;
    }

    static int foo124(char[] s, char[] t) {
        int n = strlen(s), m = strlen(t);
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return (i == n) ? 1 : 0;
    }
}
