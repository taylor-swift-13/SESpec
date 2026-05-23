
#include <string.h>

/*@
  requires \valid_read(str + (0 .. 26));
  requires \exists integer i; 0 <= i <= 26 && str[i] == 0;
  requires \forall integer i, j; 0 <= i < j < (int)strlen(str) ==> str[i] != str[j];
  assigns \nothing;
  ensures \result == 1 ==> ((int)strlen(str) <= 26 && \forall integer i, j; 0 <= i < j < (int)strlen(str) ==> str[i] != str[j]);
*/
int foo112(const char * str) {

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        
        /*@
          loop invariant 0 <= i <= len;
          loop assigns i, num;
        */
        for (int i = 0; i < len; i++) {
            char c = str[i];
            int index = c - 'a';
            if ((num & (1 << index)) != 0) {
                return 0;
            } else {
                num |= (1 << index);
            }
        }
            
        return 1;
}
