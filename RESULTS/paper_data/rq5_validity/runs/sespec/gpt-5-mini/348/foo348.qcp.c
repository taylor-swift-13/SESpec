#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cnt_not_div : Z -> Z -> Z -> Z) */
int foo348(int a, int n, int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    (i >= l) &&
    (0 <= count) &&
    (count <= i - l) &&
    ((count > 0) => (exists (k:Z), l <= k && k < i && k % a != 0)) &&
    (r == r@pre) &&
    (l == l@pre) &&
    (n == n@pre) &&
    (a == a@pre)
    */
for (int i = l; i <= r; i++) {
        if (i % a != 0) {
            count++;
        }
        if (count == n) {
            return i;
        }
    }
        return -1;
}