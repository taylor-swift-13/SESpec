#include <string.h>

/*@
    requires \valid_read(str);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> \exists integer i, j; 0 <= i < j < strlen(str) && str[i] == str[j];
    ensures \result == 1 ==> \forall integer i, j; 0 <= i < j < strlen(str) ==> str[i] != str[j];
    assigns \nothing;
*/
int isAllUnique(const char * str);

int isAllUnique(const char * str) {

        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        /*@
            loop invariant 0 <= i <= len;
            loop invariant num >= 0;
            loop invariant \forall integer j, k; 0 <= j < k < i ==> str[j] != str[k];
            loop assigns i, num;
            loop variant len - i;
        */
        for (int i = 0; i < len; i++) {
            char c = str[i];
            int index = c - 'a';
            if ((num & (1 << index)) != 0) {
                return 0;
            } else {
                num |= (1 << index);
            }
        }
        return 1;
}
