#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo136(int x);

int foo136(int x) 
/*@

Require emp
Ensure Results(__return)
*/{

        int l = 0, r = x, ans = -1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= x) => (l >= 0)) &&
((0 <= x) => (r <= x)) &&
((0 <= x) => (ans == -1 || square(ans) <= x)) &&
(x == x@pre
      loop assigns ans, l, r)
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