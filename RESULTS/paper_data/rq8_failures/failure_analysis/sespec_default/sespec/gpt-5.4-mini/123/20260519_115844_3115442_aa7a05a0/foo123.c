
#include <string.h>

/*@
  requires \valid_read(pat + (0 .. strlen(pat)));
  requires \valid_read(txt + (0 .. strlen(txt)));
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures \result == 0 ==> (strlen(pat) != strlen(txt) ||
           \exists integer k; 0 <= k < (int)strlen(pat) &&
           k < (int)strlen(txt) && pat[k] != txt[k]);
*/
int foo123(const char * pat, const char * txt) {

        int i = 0;

        /*@
          loop invariant 0 <= i;
          loop assigns i;
          loop variant (int)strlen(pat) - i;
        */
        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}
