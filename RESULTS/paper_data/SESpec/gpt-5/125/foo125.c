
#include <string.h>

/*@
  requires \valid(pat);
  requires \valid(txt);
  assigns \nothing;
            pat[k] == txt[k - (integer)strlen(pat) + (integer)strlen(txt)]);
  ensures (\result == 0) ==> ((integer)strlen(pat) == \old((integer)strlen(pat)) && (integer)strlen(txt) == \old((integer)strlen(txt)));
            (k - \old((integer)strlen(pat)) + \old((integer)strlen(txt)) < 0 || 
             pat[k] != txt[k - \old((integer)strlen(pat)) + \old((integer)strlen(txt))]));
  ensures \result == 1 || \result == 0;
*/
int foo125(const char * pat, const char * txt) {

        int i = ((int)strlen(pat)) - 1;

        /*@ 
          loop invariant i + 1 <= \at((integer)strlen(pat), Pre);
          loop invariant (integer)strlen(pat) == \at((integer)strlen(pat), Pre);
          loop invariant (integer)strlen(txt) == \at((integer)strlen(txt), Pre);
          loop invariant \forall integer k; 0 <= k < \at((integer)strlen(pat), Pre) ==> pat[k] == \at(pat[k], Pre);
          loop invariant \forall integer k; 0 <= k < \at((integer)strlen(txt), Pre) ==> txt[k] == \at(txt[k], Pre);
            (i < k && k < \at((integer)strlen(pat), Pre) &&
             0 <= k - \at((integer)strlen(pat), Pre) + \at((integer)strlen(txt), Pre) &&
             k - \at((integer)strlen(pat), Pre) + \at((integer)strlen(txt), Pre) < \at((integer)strlen(txt), Pre))
            ==> pat[k] == txt[k - \at((integer)strlen(pat), Pre) + \at((integer)strlen(txt), Pre)];
          loop assigns i;
        */
        while(i >= 0) {
            int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i] != txt[j])
                return 0;
            i = i - 1;
        }

        return 1;
}
