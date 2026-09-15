
#include <string.h>

/*@
  requires \valid_read(str + (0..100));
  requires \exists integer n; 0 <= n <= 100 && str[n] == '\0';
  requires \forall integer i; 0 <= i < 100 ==> 0 <= str[i] <= 100;
  assigns \nothing;
           \forall integer x, y; 0 <= x < y < (int)strlen(str) ==> str[x] != str[y]);
  ensures \result == 0 || \result == 1;
*/
int foo112(const char * str) {

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        
        /*@
          loop invariant 0 <= i <= len;
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
