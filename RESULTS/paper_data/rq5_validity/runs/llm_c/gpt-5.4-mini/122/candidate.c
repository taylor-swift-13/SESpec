#include <string.h>

/*@
    requires s != \null;
    requires \valid_read(s + (0 .. strlen(s)));
    assigns \nothing;
    ensures \result == 1 || \result == 0;
*/
int isPalindrome(const char * s);

 /*@ 
    requires s != \null;
    requires \valid_read(s + (0 .. strlen(s)));
    assigns \nothing;
    ensures \result == 1 || \result == 0;
*/
int isPalindrome(const char * s) {

        int n = ((int)strlen(s));

        /*@
            loop invariant 0 <= i <= ((int)strlen(s));
            loop invariant \forall integer j; 0 <= j < i ==> s[j] == s[n - 1 - j];
            loop assigns i;
            loop variant ((int)strlen(s)) - i;
        */
        for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i) != s[n - 1 - i)) {
                return 0;
            }
        }

        return 1;
}
