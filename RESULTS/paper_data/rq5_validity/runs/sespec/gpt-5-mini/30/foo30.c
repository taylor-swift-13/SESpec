
#include <stdlib.h>

int foo30();


/*@ predicate valid_int_array{L}(int *p, integer n) =
      p != \null && \valid(p + (0 .. n-1));
*/
/*@
  assigns \nothing;
  ensures \result == 0 || \result == 1;
*/
int foo30() {

    int *i = (int *)malloc(sizeof(int) * (10));
    int i_len = 10;
    return i[3] == 0;
}
