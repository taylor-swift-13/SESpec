#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo136(int x) 
/*@

Require emp
Ensure Results(__return)
*/{

        int l = 0, r = x, ans = -1;
       
  /*@ Inv
    (x == x@pre) &&
    (-1 <= ans) &&
    ((0 <= x@pre) => (0 <= l)) &&
    ((0 <= x@pre) => (-1 <= r)) &&
    ((0 <= x@pre) => (r <= x@pre)) &&
    ((0 <= x@pre) => (l <= r + 1)) &&
    ((0 <= x@pre) => (ans < l)) &&
    ((0 <= x@pre) => (ans == -1 || (long)ans * (long)ans <= x)) &&
    ((0 <= x@pre) => (l == 0 || (long)(l - 1) * (long)(l - 1) <= x))
    */
while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long) mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
        return ans;
}