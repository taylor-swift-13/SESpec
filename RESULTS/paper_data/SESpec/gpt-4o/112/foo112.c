
#include <string.h>

/*@
  logic integer count_bits_set(int num) =
    num == 0 ? 0 : (num & 1) + count_bits_set((int)(num >> 1));
*/

/*@
  requires \valid_read(str + (0 .. strlen(str) - 1));
  assigns \nothing;
*/
int foo112(const char * str) {
    /*@ assert \valid_read(str + (0 .. strlen(str) - 1)); */
    int len = ((int)strlen(str));
    if (len > 26) {
        return 0;
    }
    int num = 0;

    /*@
      loop invariant \valid_read(str + (0 .. len - 1));
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
