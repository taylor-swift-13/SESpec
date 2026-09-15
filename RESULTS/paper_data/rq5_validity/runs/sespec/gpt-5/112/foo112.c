
#include <string.h>

/*@ predicate in_prefix(char *s, integer i, integer idx) =
      0 <= idx && idx < 26 &&
      (\exists integer k; 0 <= k < i && s[k] >= 'a' && s[k] <= 'z' && (s[k] - 'a') == idx);
*/

/*@
  requires \valid_read(str + (0 .. strlen(str)));
  requires \forall integer k; 0 <= k < (integer)strlen(str) ==> ('a' <= str[k] && str[k] <= 'z');
  assigns \nothing;
  ensures \at(str,Pre) == str;
*/
int foo112(const char * str) {
        int len = ((int)strlen(str));
        if (len > 26) {
            return 0;
        }
        int num = 0;
        /*@
          loop invariant \forall integer k; 0 <= k < len ==> str[k] == \at(str[k], Pre);
                                <==> (\exists integer j; 0 <= j < i && (str[j] - 'a') == idx));
          loop assigns i, num;
          loop variant len - i;
        */
        for (int i = 0; i < len; i++) {
            char c = str[i];
            int index = c - 'a';
            /*@ assert 0 <= index <= 25; */
            if ((num & (1 << index)) != 0) {
                return 0;
            } else {
                num |= (1 << index);
            }
        }
        return 1;
}
