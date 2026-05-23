
#include <string.h>

/*@
  requires \valid(s1);
  assigns \nothing;
*/
int foo19(const char * s1);


/*@
  requires \valid(s1);
  assigns \nothing;
  ensures (\result == 1 && (int)strlen(s1) == 24) || (\result == 0 && (int)strlen(s1) != 24);
*/
int foo19(const char * s1) {
    return ((int)strlen(s1)) == 24;
}
