#include <string.h>

/*@
    requires \valid_read(s + (0 .. strlen(s)));
    ensures \result == 1 <==> (\forall integer i; 0 <= i < strlen(s) / 2 ==> s[i] == s[strlen(s) - 1 - i]);
    ensures \result == 0 <==> !(\forall integer i; 0 <= i < strlen(s) / 2 ==> s[i] == s[strlen(s) - 1 - i]);
    assigns \nothing;
*/
int isPalindrome(const char * s);

int isPalindrome(const char * s) {

        int n = ((int)strlen(s));

        /*@
            loop invariant 0 <= i <= n;
            loop invariant \forall integer j; 0 <= j < i ==> s[j] == s[n - 1 - j];
            loop assigns i;
            loop variant n - i;
        */
        for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }

        return 1;
}
