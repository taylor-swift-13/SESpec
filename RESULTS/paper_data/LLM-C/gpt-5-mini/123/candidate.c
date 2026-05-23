#include <string.h>

int isPrefix(const char * pat, const char * txt);

/*@
    requires \valid_read(pat + (0..\strlen(pat)));
    requires \valid_read(txt + (0..\strlen(txt)));
    assigns \nothing;
    ensures \result == 1 <==> (\strlen(pat) <= \strlen(txt) && \forall integer k; 0 <= k < \strlen(pat) ==> pat[k] == txt[k]);
*/
int isPrefix(const char * pat, const char * txt) {

        int i = 0;

        /*@
            loop invariant 0 <= i <= (int)\strlen(pat);
            loop invariant \forall integer j; 0 <= j < i ==> pat[j] == txt[j];
            loop assigns i;
            loop variant (int)\strlen(pat) - i;
        */
        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}
