
#include <string.h>

int foo123(const char * pat, const char * txt) {

        int i = 0;

        /*@
          loop invariant 0 <= i;
          loop invariant \forall integer k; 0 <= k < i ==> pat[k] == txt[k];
          loop assigns i;
        */
            while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}
