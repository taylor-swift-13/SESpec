#include <string.h>

/*@
    requires \valid_read(pat + (0 .. \strlen(pat)));
    requires \valid_read(txt + (0 .. \strlen(txt)));
    assigns \nothing;
    ensures (\result == 1) <==> (
        \strlen(pat) <= \strlen(txt) &&
        \forall integer k; 0 <= k < \strlen(pat) ==>
            pat[k] == txt[\strlen(txt) - \strlen(pat) + k]
    );
    ensures (\result == 0) <==> !(
        \strlen(pat) <= \strlen(txt) &&
        \forall integer k; 0 <= k < \strlen(pat) ==>
            pat[k] == txt[\strlen(txt) - \strlen(pat) + k]
    );
*/
int isSuffix(const char * pat, const char * txt) {

        int i = ((int)strlen(pat)) - 1;

        /*@
            loop invariant -1 <= i <= (int)\strlen(pat) - 1;
            loop invariant \forall integer k; i < k <= (int)\strlen(pat) - 1 ==>
                pat[k] == txt[(int)\strlen(txt) - (int)\strlen(pat) + k];
            loop assigns i;
            loop variant i + 1;
        */
        while(i >= 0) {
            int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i] != txt[j])
                return 0;
            i = i - 1;
        }

        return 1;
}
