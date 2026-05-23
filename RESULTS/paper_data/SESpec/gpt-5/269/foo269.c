
#include <stdlib.h>

/* No top-level logic or predicate definitions are needed. */

int foo269(int dim, int w) {

    int count = 1000000007;
    int *div = (int *)malloc(sizeof(int) * (dim + 1));
    int div_len = dim + 1;
    div[0] = 1;
    div[1] = w;
    div[2] = w * w;
        
    /*@ 
      loop invariant div_len == dim + 1;
      loop invariant div[0] == 1;
      loop invariant div[1] == w;
      loop invariant div[2] == w * w;
      loop invariant 0 <= div[0] < count;
      loop assigns div[0 .. dim];
    */
    for (int d = 3; d <= dim; d++) {
        div[d] = ((w - 1)
                * (div[d - 1] + div[d - 2])) % count;
    }
        
    return div[dim];
}
