
/*@ predicate c_string{L}(char *s) =
      \exists integer n; \valid_read(s + (0 .. n)) && s[n] == '\0';
*/

        /*@
        */

/*@
  requires c_string((char *)s1);
  requires \strlen(s1) > 0 ==> \valid_read(s2 + (0 .. (int)\strlen(s1) - 1));
  assigns \nothing;
  ensures \result == 0 <==> \exists integer k; 0 <= k < (int)\strlen(s1) && s1[k] == s2[(int)\strlen(s1) - 1 - k];
  ensures \result == 1 <==> \forall integer k; 0 <= k < (int)\strlen(s1) ==> s1[k] != s2[(int)\strlen(s1) - 1 - k];
  ensures \strlen(s1) == 0 ==> \result == 1;
  ensures \strlen(s1) > 0 ==> (\result == 0 || \result == 1);
*/
int foo20(const char *s1, const char *s2) {
    int i = 0;
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= (int)\strlen(s1);
          loop invariant -1 <= count <= (int)\strlen(s1) - 1;
          loop invariant i + count == (int)\strlen(s1) - 1;
          loop assigns count, i;
            */
            for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
            
    return 1;
}
