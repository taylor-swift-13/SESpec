
#include <string.h>

/*@
  requires \valid_read(pat) && \valid_read(txt);
  requires valid_string(pat);
  requires valid_string(txt);
  assigns \nothing;
  ensures (\result == 0) ==> ((\exists integer k; 0 <= k < (int)strlen(pat) && (k >= (int)strlen(txt) || pat[k] != txt[k])));
  ensures \result == 0 || \result == 1;
  ensures \result == \result;
  ensures \result == 0 ==> ((\exists integer k; 0 <= k < (int)strlen(pat) && (k >= (int)strlen(txt) || pat[k] != txt[k])));
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
