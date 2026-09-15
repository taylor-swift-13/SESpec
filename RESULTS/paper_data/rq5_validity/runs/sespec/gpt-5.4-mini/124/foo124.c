
/*@
  logic boolean subseq(char *s, char *t, integer i, integer j) =
    i <= 0 ? \true :
    j <= 0 ? \false :
    (s[i - 1] == t[j - 1] && subseq(s, t, i - 1, j - 1)) || subseq(s, t, i, j - 1);
*/

/*@
  logic integer cstrlen(char *s) =
    s == \null ? 0 : (*s == 0 ? 0 : 1 + cstrlen(s + 1));
*/
/*@
  requires \exists integer ls; 0 <= ls && s[ls] == 0 && \valid_read(s + (0 .. ls));
  requires \exists integer lt; 0 <= lt && t[lt] == 0 && \valid_read(t + (0 .. lt));
  assigns \nothing;
  ensures 0 <= \result <= 1;
*/
int foo124(const char * s, const char * t) {

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant 0 <= j;
          loop invariant i <= j;
          loop invariant i == 0 || subseq((char *)s, (char *)t, i, j);
          loop invariant subseq((char *)s, (char *)t, i, j);
          loop invariant \forall integer k; 0 <= k < i ==> 0 <= k < n;
          loop invariant \forall integer k; 0 <= k < j ==> 0 <= k < m;
          loop invariant \forall integer k; 0 <= k < n ==> s[k] == \at(s[k], Pre);
          loop invariant \forall integer k; 0 <= k < m ==> t[k] == \at(t[k], Pre);
          loop invariant (i < n && j < m) ==> (s[i] != t[j] || subseq((char *)s, (char *)t, i + 1, j + 1));
          loop invariant (!(i < n && j < m)) ==> (i >= 0 && j >= 0);
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
