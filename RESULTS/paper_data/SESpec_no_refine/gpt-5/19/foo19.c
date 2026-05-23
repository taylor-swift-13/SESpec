#include <string.h>

/*@
  requires \valid(s1);
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo19(const char * s1);


int foo19(const char * s1) {

    return ((int)strlen(s1)) == 24;
}