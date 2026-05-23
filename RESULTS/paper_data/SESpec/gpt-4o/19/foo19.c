#include <string.h>

/*@
  requires \valid(s1);
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo19(const char * s1);


/*@
  predicate valid_string{L}(const char* s) =
      \valid(s) && \exists integer n; n >= 0 && \valid_read(s+(0..n)) && s[n] == '\0';

  /*@
    requires valid_string(s1);
    assigns \nothing;
    ensures \result == 1 <==> \strlen(s1) == 24;
    ensures \result == 0 <==> \strlen(s1) != 24;
  */
/*@
    requires valid_string(s1);
    assigns \nothing;
    ensures \result == 1 <==> \strlen(s1) == 24;
    ensures \result == 0 <==> \strlen(s1) != 24;
  */
*/
int foo19(const char * s1) {
    return ((int)strlen(s1)) == 24;
}