#include <string.h>

/*@
    requires \valid_read(pat + (0 .. strlen(pat) - 1));
    requires \valid_read(txt + (0 .. strlen(txt) - 1));
    ensures \result == 1 <==> (\exists integer k; 0 <= k <= strlen(txt) - strlen(pat) &&
                               \forall integer i; 0 <= i < strlen(pat) ==> pat[i] == txt[k + i]);
    ensures \result == 0 <==> !(\exists integer k; 0 <= k <= strlen(txt) - strlen(pat) &&
                                \forall integer i; 0 <= i < strlen(pat) ==> pat[i] == txt[k + i]);
    assigns \nothing;
*/
int isSuffix(const char * pat, const char * txt);

int isSuffix(const char * pat, const char * txt) {

        int i = ((int)strlen(pat)) - 1;

        /*@
            loop invariant -1 <= i && i < (int)strlen(pat);
            loop invariant \forall integer k; i < k < (int)strlen(pat) ==> 
                            (\exists integer j; j >= 0 && j < (int)strlen(txt) && pat[k] == txt[j]);
            loop assigns i;
            loop variant i;
        */
        while(i >= 0) {
	    int j = i - ((int)strlen(pat)) + ((int)strlen(txt));
            if(j < 0 || pat[i] != txt[j])
                return 0;
            i = i - 1;
        }

        return 1;
}
