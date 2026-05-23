
/*@ logic integer strlen(char *s) =
      *s == '\0' ? 0 : 1 + strlen(s + 1);
*/

/*@
  requires \valid_read(s1 + (0 .. strlen(s1)));
  requires \valid_read(s2 + (0 .. strlen(s1) - 1));
  assigns \nothing;
  
  ensures \result == 0 || \result == 1;
*/
int foo20(const char *s1, const char *s2) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i;
      loop invariant \forall integer k; 0 <= k < i ==> s1[k] == \at(s1[k], Pre);
      loop invariant \forall integer k; 0 <= k < i ==> s2[k] == \at(s2[k], Pre);
      loop assigns count, i;
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    
    return 1;
}
