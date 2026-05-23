
/*@
  predicate cstring{L}(const char *s) =
    \exists integer n;
      0 <= n &&
      \valid_read(s + (0 .. n)) &&
      s[n] == '\0';
*/

int foo122(const char * s) {

        int n = ((int)strlen(s));

        /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> s[k] == s[n - 1 - k];
          loop assigns i;
        */
        for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }

        return 1;
}
