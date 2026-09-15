
#include <stdlib.h>

/*@
  logic integer init_val(integer k) = k + 1;
*/
/*@
        predicate arrays_equal_prefix{L}(int *a, int *b, integer c) =
          \forall integer k; 0 <= k < c ==> a[k] == b[k];
        */

        /*@
        logic integer count_even_prefix(int* a, integer hi) =
          hi <= 0 ? 0 : count_even_prefix(a, hi - 1) + ((a[hi - 1] % 2 == 0) ? 1 : 0);
        */
        

/*@
  assigns \nothing;
  ensures (1 <= p && 2*p - 1 <= number) ==> \result == 2*p - 1;
  ensures (!(1 <= p && 2*p - 1 <= number) && (1 <= p && 2*p <= number)) ==> \result == 2*p;
  ensures (!(1 <= p && 2*p - 1 <= number) && !(1 <= p && 2*p <= number)) ==> \result == 0;
*/
int foo152(int number, int p) {
    ...
}
