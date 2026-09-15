
#include <string.h>

/*@ predicate in_prefix(char *s, integer i, integer idx) =
      0 <= idx && idx < 26 &&
      (\exists integer k; 0 <= k < i && s[k] >= 'a' && s[k] <= 'z' && (s[k] - 'a') == idx);
*/

int foo112(const char * str) {

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < len ==> str[k] == \at(str[k], Pre);
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
