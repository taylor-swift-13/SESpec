class Sespec0124 {
    /*@ requires s != null;
      @ ensures 0 <= \result && \result <= s.length;
      @ ensures (\forall int i; 0 <= i && i < \result; s[i] != '\0');
      @ ensures \result == s.length || s[\result] == '\0';
      @*/
    static int strlen(char[] s) {
        int len = 0;
        //@ maintaining 0 <= len && len <= s.length;
        //@ maintaining (\forall int i; 0 <= i && i < len; s[i] != '\0');
        //@ decreases s.length - len;
        while (len < s.length && s[len] != '\0') {
            len++;
        }
        return len;
    }

    /*@ requires s != null && t != null;
      @ ensures \result == 0 || \result == 1;
      @ ensures \result == 1 ==>
      @   (\exists int N; 0 <= N && N <= s.length &&
      @          (\forall int p; 0 <= p && p < N; s[p] != '\0') &&
      @          (N == s.length || s[N] == '\0') &&
      @     (\exists int M; 0 <= M && M <= t.length &&
      @          (\forall int q; 0 <= q && q < M; t[q] != '\0') &&
      @          (M == t.length || t[M] == '\0') &&
      @          (\forall int p; 0 <= p && p < N; (\exists int q; 0 <= q && q < M; s[p] == t[q]))));
      @*/
    static int foo124(char[] s, char[] t) {
        int n = strlen(s), m = strlen(t);
        int i = 0, j = 0;

        //@ maintaining 0 <= i && i <= n && 0 <= j && j <= m;
        //@ maintaining (\forall int p; 0 <= p && p < i; (\exists int q; 0 <= q && q < j; s[p] == t[q]));
        //@ decreases (m - j) + (n - i);
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return (i == n) ? 1 : 0;
    }
}