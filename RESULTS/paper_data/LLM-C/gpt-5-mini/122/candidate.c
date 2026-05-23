#include <string.h>

int isPalindrome(const char * s);

/*@
    requires s != \null;
    requires \valid_read(s + (0 .. \strlen(s)));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (int)\strlen(s) ==> s[i] == s[(int)\strlen(s) - 1 - i]);
    ensures \result == 0 <==> (\exists integer i; 0 <= i < (int)\strlen(s) && s[i] != s[(int)\strlen(s) - 1 - i]);
    ensures \result == 0 || \result == 1;
*/
int isPalindrome(const char * s) {

        int n = ((int)strlen(s));

        /*@
            loop invariant 0 <= i <= n;
            loop invariant n == (int)strlen(s);
            loop invariant \forall integer j; 0 <= j < i ==> s[j] == s[n - 1 - j];
            loop assigns i;
            loop variant n - i;
        */
        for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i) != s[n - 1 - i)) {
                return 0;
            }
        }

        return 1;
}
