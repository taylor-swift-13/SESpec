#include <string.h>

/*@
    requires \valid_read(pat + (0 .. strlen(pat)));
    requires \valid_read(txt + (0 .. strlen(txt)));
    ensures \result == 1 ==> \forall integer i; 0 <= i < strlen(pat) ==> pat[i] == txt[i];
    ensures \result == 0 ==> \exists integer i; 0 <= i < strlen(pat) && (i >= strlen(txt) || pat[i] != txt[i]);
    assigns \nothing;
*/
int isPrefix(const char * pat, const char * txt);

int isPrefix(const char * pat, const char * txt) {

        int i = 0;

        /*@
            loop invariant 0 <= i <= strlen(pat);
            loop invariant \forall integer j; 0 <= j < i ==> pat[j] == txt[j];
            loop assigns i;
            loop variant strlen(pat) - i;
        */
        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i] != txt[i])
                return 0;
            i = i + 1;
        }

        return 1;
}
