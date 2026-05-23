#include <string.h>

/*@ 
    requires pat != \null;
    requires txt != \null;
    requires \valid_read(pat + (0 .. strlen(pat)));
    requires \valid_read(txt + (0 .. strlen(txt)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> strlen(pat) <= strlen(txt);
    ensures \result == 1 ==> \forall integer i; 0 <= i < (int)strlen(pat) ==> pat[i] == txt[i];
    ensures \result == 0 ==> (\exists integer i; 0 <= i < (int)strlen(pat) && (i >= (int)strlen(txt) || pat[i] != txt[i]));
*/
int isPrefix(const char * pat, const char * txt);

 /*@ 
    requires pat != \null;
    requires txt != \null;
    requires \valid_read(pat + (0 .. strlen(pat)));
    requires \valid_read(txt + (0 .. strlen(txt)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> strlen(pat) <= strlen(txt);
    ensures \result == 1 ==> \forall integer i; 0 <= i < (int)strlen(pat) ==> pat[i] == txt[i];
    ensures \result == 0 ==> (\exists integer i; 0 <= i < (int)strlen(pat) && (i >= (int)strlen(txt) || pat[i] != txt[i]));
*/
int isPrefix(const char * pat, const char * txt) {

        int i = 0;

        /*@ 
            loop invariant 0 <= i <= (int)strlen(pat);
            loop invariant \forall integer j; 0 <= j < i ==> j < (int)strlen(txt) && pat[j] == txt[j];
            loop assigns i;
            loop variant (int)strlen(pat) - i;
        */
        while(i < ((int)strlen(pat))) {
            if(i >= ((int)strlen(txt)) || pat[i) != txt[i))
                return 0;
            i = i + 1;
        }

        return 1;
}
