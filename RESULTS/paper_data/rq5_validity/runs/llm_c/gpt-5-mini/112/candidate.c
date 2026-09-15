#include <string.h>

/*@
    requires \valid_read(str + (0 .. strlen(str)));
    requires \forall integer i; 0 <= i < (int)strlen(str) ==> 'a' <= str[i] <= 'z';
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures (int)strlen(str) > 26 ==> \result == 0;
    ensures \result == 1 ==> (\forall integer i, j; 0 <= i < j < (int)strlen(str) ==> str[i] != str[j]);
    ensures \result == 0 ==> ((int)strlen(str) > 26) || (\exists integer i, j; 0 <= i < j < (int)strlen(str) && str[i] == str[j]);
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
            loop invariant \forall integer j; 0 <= j < i ==> 'a' <= str[j] <= 'z';
            loop invariant \forall integer j, k; 0 <= j < k < i ==> str[j] != str[k];
            loop invariant \forall integer b; 0 <= b < 26 ==>
                ((num & (1 << b)) != 0) <==> (\exists integer t; 0 <= t < i && (str[t] - 'a') == b);
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
