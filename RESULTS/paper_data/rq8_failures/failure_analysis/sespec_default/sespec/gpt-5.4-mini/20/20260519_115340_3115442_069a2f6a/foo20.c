
/*@
  logic integer strlen_l(const char *s, integer i) =
    s[i] == '\0' ? i : strlen_l(s, i + 1);
*/

/*@
  requires \valid(&s1[0] + (0..s2-1));
  requires \forall integer i; 0 <= i < s2 ==> 0 <= s1[i] <= 100;
  requires s2 > 0;
  requires s2 < 100;
  requires \valid(&s2[0] + (0..100-1));
  requires \forall integer i; 0 <= i < 100 ==> 0 <= s2[i] <= 100;
  assigns i;
  ensures \result == 0 || \result == 1;
  ensures \result == 0 ==> (\exists integer k; 0 <= k < strlen_l(s1, 0) && s1[strlen_l(s1, 0) - 1 - k] == s2[k]);
  ensures \result == 1 ==> (\forall integer k; 0 <= k < strlen_l(s1, 0) ==> s1[strlen_l(s1, 0) - 1 - k] != s2[k]);
*/
int foo20(const char *s1, const char *s2) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i;
      loop invariant i <= strlen_l(s1, 0);
      loop invariant \forall integer k; 0 <= k < i ==> s2[k] == \at(s2[k], Pre);
      loop invariant \forall integer k; 0 <= k < strlen_l(s1, 0) ==> s1[k] == \at(s1[k], Pre);
      loop invariant \forall integer k; 0 <= k < i ==> s2[k] != s1[strlen_l(s1, 0) - 1 - k];
      loop assigns i;
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    
    return 1;
}
