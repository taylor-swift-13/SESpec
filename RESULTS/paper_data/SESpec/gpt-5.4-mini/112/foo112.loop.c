
#include <string.h>

int foo112(const char * str) {

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        
        /*@
          loop invariant 0 <= i;
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
