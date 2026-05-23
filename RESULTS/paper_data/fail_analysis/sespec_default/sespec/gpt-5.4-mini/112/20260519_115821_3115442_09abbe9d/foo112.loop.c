
#include <string.h>

int foo112(const char * str) {

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= len;
          loop invariant \forall integer k; 0 <= k < i ==> str[k] >= 'a' && str[k] <= 'z';
          loop invariant \forall integer k; 0 <= k < i ==> (num & (1 << (str[k] - 'a'))) != 0;
          loop invariant \forall integer x, y; 0 <= x < y < i ==> str[x] != str[y];
          loop assigns i, c, index, num;
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
