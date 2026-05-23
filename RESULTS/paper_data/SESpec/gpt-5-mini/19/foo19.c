
#include <string.h>

/*@
  requires s1 != \null && \exists integer i; i >= 0 && s1[i] == '\0';
  assigns \nothing;
*/
int foo19(const char * s1);


/*@
  requires s1 != \null
           && \exists integer i; i >= 0 && \valid_read(s1 + (0 .. i)) && s1[i] == '\0';
  assigns \nothing;
*/
int foo19(const char * s1) {

    return ((int)strlen(s1)) == 24;
}
