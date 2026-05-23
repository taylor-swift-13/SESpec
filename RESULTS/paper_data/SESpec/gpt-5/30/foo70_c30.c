#include <stdlib.h>

int foo70_c30();


/*@
  ensures \true;
*/
int foo70_c30() {

    int *i = (int *)malloc(sizeof(int) * (10));
    int i_len = 10;
    return i[3] == 0;
}