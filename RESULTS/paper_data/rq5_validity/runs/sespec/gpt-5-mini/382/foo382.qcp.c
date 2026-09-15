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
    ((max == 0) || (1 <= max && max <= i-1)) &&
    ((forall (k:Z), 1 <= k && k <= i-1 => ((k % x == y) => (max >= k)))) &&
    ((forall (k:Z), 1 <= k && k <= i-1 => ((max == k) => (k % x == y)))) &&
    ((exists (k:Z), 1 <= k && k <= i-1 && (k % x == y)) => (max != 0)) &&
    ((forall (k:Z), 1 <= k && k <= i-1 => (max >= k) || (k % x != y))) &&
    ((forall (k:Z), i <= k && k <= n@pre => ((k % x == y) => (k > max)))) &&
    ((n@pre >= 0) => ((i <= n@pre) => (1 <= i))) &&
    ((i <= n@pre) => (max <= n@pre)) &&
    ((i <= n@pre) => ((max == 0) || (max % x == y))) &&
    ((i <= n@pre) => (((max == 0) && (y == y@pre) && (x == x@pre) && (n == n@pre)) || (max >= 1 && max <= n@pre && (max % x == y)))) &&
    (y == y@pre) &&
    (x == x@pre) &&
    (n == n@pre)
    */
for (int i = 1; i <= n; i++) {
        if ((i % x) == y) {
            max = i;
        }
    }
        return max;
}