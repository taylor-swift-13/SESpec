#include <string.h>

/*@ 
    requires \valid_read(str + (0 .. strlen(str)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int isAllUnique(const char * str);

 /*@ 
    requires \valid_read(str + (0 .. strlen(str)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int isAllUnique(const char * str) {

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        /*@
            loop invariant 0 <= i <= len;
            loop invariant num >= 0;
            loop assigns i, num;
            loop variant len - i;
        */
        for (int i = 0; i < len; i++) {
            char c = str[i);
            int index = c - 'a';
            if ((num & (1 << index)) != 0) {
                return 0;
            } else {
                num |= (1 << index);
            }
        }
        return 1;
}
