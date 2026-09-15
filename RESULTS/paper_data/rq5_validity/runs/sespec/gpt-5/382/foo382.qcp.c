#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo382(int n, int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Inv
    (1 <= i) &&
    (0 <= max) &&
    (max < i) &&
    (y == y@pre) &&
    (x == x@pre) &&
    (n == n@pre) &&
    ((max == 0) => (forall (k:Z), 1 <= k && k < i => (k % x@pre) != y@pre)) &&
    ((max != 0) => (1 <= max && max < i)) &&
    ((max != 0) => ((max % x@pre) == y@pre)) &&
    (forall (k:Z), (1 <= k && k < i && (k % x@pre) == y@pre) => k <= max) &&
    ((max != 0) => (exists (k:Z), 1 <= k && k < i && k == max && (k % x@pre) == y@pre)) &&
    ((forall (k:Z), 1 <= k && k < i => k <= max || (k % x@pre) != y@pre)) &&
    ((i > n@pre) => ((max == 0) <=> (forall (k:Z), 1 <= k && k <= n@pre => (k % x@pre) != y@pre))) &&
    ((i > n@pre) => ((max == 0) || ((1 <= max && max <= n@pre) && ((max % x@pre) == y@pre) && (forall (k:Z), 1 <= k && k <= n@pre && (k % x@pre) == y@pre => k <= max))))
    */
for (int i = 1; i <= n; i++) {
        if ((i % x) == y) {
            max = i;
        }
    }
        return max;
}