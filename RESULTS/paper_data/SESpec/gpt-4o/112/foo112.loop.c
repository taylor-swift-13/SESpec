
#include <string.h>

/*@
  logic integer count_bits_set(int num) =
    num == 0 ? 0 : (num & 1) + count_bits_set((int)(num >> 1));
*/

/*@
  requires \valid_read(str + (0 .. strlen(str) - 1));
  ensures \result == 1 ==> \forall integer i, j; 0 <= i < j < strlen(str) ==> str[i] != str[j];
  ensures \result == 0 ==> \exists integer i, j; 0 <= i < j < strlen(str) && str[i] == str[j];
*/
int foo112(const char * str) {
    int len = ((int)strlen(str));
    if (len > 26) {
        return 0;
    }
    int num = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < len ==> str[k] == \at(str[k], Pre);
      loop assigns i, num;
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
