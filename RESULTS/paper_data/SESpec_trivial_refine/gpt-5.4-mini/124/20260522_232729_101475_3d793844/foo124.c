
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
predicate subseq{L}(char *s, char *t) =
  *s == '\0' ||
  (*t != '\0' && ((*s == *t && subseq{L}(s + 1, t + 1)) || subseq{L}(s, t + 1)));
*/
/*@
  requires \valid_read_string(s);
  requires \valid_read_string(t);
  assigns \nothing;
  ensures \result == (subseq(s, t) ? 1 : 0);
  ensures \result == 1 <==> subseq(s, t);
  ensures \result == 0 <==> !subseq(s, t);
  ensures subseq(s, t) ==> strlen(s) <= strlen(t);
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
