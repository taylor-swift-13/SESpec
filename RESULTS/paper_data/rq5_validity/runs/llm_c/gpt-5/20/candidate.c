#include <string.h>

int f(const char *s1, const char *s2);

/*@ 
  requires s1 != \null;
  requires \valid_read(s1 + (0 .. \strlen(s1)));
  requires \strlen(s1) == 0 || \valid_read(s2 + (0 .. \strlen(s1) - 1));
  assigns \nothing;
  ensures (\result == 0) <==> (\exists integer k; 0 <= k < \strlen(s1) && s1[\strlen(s1) - 1 - k] == s2[k]);
  ensures (\result == 0) ==> (\exists integer k; 0 <= k < \strlen(s1) &&
                              s1[\strlen(s1) - 1 - k] == s2[k] &&
                              (\forall integer j; 0 <= j < k ==> s1[\strlen(s1) - 1 - j] != s2[j]));
*/
int f(const char *s1, const char *s2) {
    int i = 0;
    /*@
      loop invariant 0 <= i <= \strlen(s1);
      loop invariant -1 <= count <= \strlen(s1) - 1;
      loop invariant (count >= 0 ==> i + count == \strlen(s1) - 1);
      loop invariant (\forall integer j; 0 <= j < i ==> s1[\strlen(s1) - 1 - j] != s2[j]);
      loop assigns i, count;
      loop variant count + 1;
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    return 1;
}
