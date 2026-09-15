
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/


int foo124(const char * s, const char * t) {

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

        /*@
          loop invariant 0 <= i;
          loop invariant 0 <= j;
          loop invariant i <= j;
          loop assigns i, j;
        */
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
            
        return i == n;
}
