
#include <string.h>

/*@
  requires \exists integer n; 0 <= n && \valid_read(s1 + (0 .. n)) && s1[n] == '\0';
  assigns \nothing;
  ensures \result == (((int)strlen(s1)) == 24);
  ensures \result == 1 <==> ((int)strlen(s1) == 24);
*/
int foo19(const char *s1);

/*@
  requires \exists integer n; 0 <= n && \valid_read(s1 + (0 .. n)) && s1[n] == '\0';
  assigns \nothing;
  ensures \result == (((int)strlen(s1)) == 24);
  ensures \result == 1 <==> ((int)strlen(s1) == 24);
*/
int foo19(const char *s1) {
  return ((int)strlen(s1)) == 24;
}
