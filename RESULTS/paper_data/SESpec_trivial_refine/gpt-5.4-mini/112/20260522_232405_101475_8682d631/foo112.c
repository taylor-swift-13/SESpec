
#include <string.h>

/*@
predicate no_dup_lower(char *s, integer n) = 
  \forall integer j, k; 0 <= j < k < n ==> s[j] != s[k];
*/

/*@
  requires \valid_read(str + (0 .. 26));
  requires \exists integer i; 0 <= i <= 26 && str[i] == '\0';
  requires \forall integer i; 0 <= i < strlen(str) ==> 'a' <= str[i] <= 'z';
  assigns \nothing;
*/
int foo112(const char *str) {
    int len = (int)strlen(str);
    if (len > 26) {
        return 0;
    }

    unsigned int num = 0;

    /*@
      loop invariant 0 <= i <= len;
      loop assigns i, num;
      loop variant len - i;
    */
    for (int i = 0; i < len; i++) {
        char c = str[i];
        int index = c - 'a';

        if ((num & (1U << index)) != 0U) {
            return 0;
        } else {
            num |= (1U << index);
        }
    }

    return 1;
}
