
#include <stdlib.h>

/*@ logic integer foo269_div(integer n, integer w) =
      n == 0 ? 1 :
      n == 1 ? w :
      n == 2 ? w * w :
      ((w - 1) * (foo269_div(n - 1, w) + foo269_div(n - 2, w))) % 1000000007; */

/*@
  requires dim >= 0;
  requires 0 <= w <= 1000000006;
  decreases dim;
  assigns \result \from dim, w;
*/
int foo269(int dim, int w) {
    const int count = 1000000007;

    if (dim == 0) {
        return 1;
    }

    if (dim == 1) {
        return w;
    }

    if (dim == 2) {
        return (int)(((long long)w * (long long)w) % count);
    }

    return (int)(((long long)(w - 1) *
                  ((long long)foo269(dim - 1, w) + (long long)foo269(dim - 2, w)))
                 % count);
}
