#include <string.h>

/*@ predicate is_cstring{L}(char const *s) =
      s != \null &&
      \exists integer n; n >= 0 &&
        \valid_read(s + (0 .. n)) &&
        s[n] == '\0' &&
        (\forall integer k; 0 <= k < n ==> s[k] != '\0');
*/

/*@ 
  requires is_cstring(s1);
  assigns \nothing;
  ensures (\result == 1) <==> (\strlen(s1) == 24);
  ensures 0 <= \result <= 1;
*/
int f(const char * s1);

int f(const char * s1) {

    return ((int)strlen(s1)) == 24;
}
