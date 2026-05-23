#include <string.h>

/*@ 
    requires pat != \null;
    requires txt != \null;
    requires \valid_read(pat + (0 .. (int)strlen(pat)));
    requires \valid_read(txt + (0 .. (int)strlen(txt)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int isSuffix(const char * pat, const char * txt);

 /*@ 
    requires pat != \null;
    requires txt != \null;
    requires \valid_read(pat + (0 .. (int)strlen(pat)));
    requires \valid_read(txt + (0 .. (int)strlen(txt)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int isSuffix(const char * pat, const char * txt) {

        int i = ((int)strlen(pat)) - 1;
        /*@
            loop invariant -1 <= i < (int)strlen(pat);
            loop invariant \forall integer k; i < k < (int)strlen(pat) ==> pat[k] == txt[k - (int)strlen(pat) + (int)strlen(txt)];
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
