
#include <string.h>

/*@
  requires \valid_read(pat);
  requires \valid_read(txt);
*/
int foo123(const char * pat, const char * txt) {

        int i = 0;

        /*@
          loop invariant 0 <= i;
          loop invariant \forall integer k; 0 <= k < (int)strlen(pat) ==> pat[k] == \at(pat[k], Pre);
          loop invariant \forall integer k; 0 <= k < (int)strlen(txt) ==> txt[k] == \at(txt[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> k < (int)strlen(txt);
          loop invariant \forall integer k; 0 <= k < i ==> pat[k] != '\0' && txt[k] != '\0';
          loop invariant (!(i < ((int)strlen(pat)))) ==> \true;
          loop assigns i;
        */
        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}
