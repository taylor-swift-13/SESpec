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
       
  /*0*/ 
 /*@ Inv
    (l >= 0) &&
    (r <= x) &&
    (l <= r + 1) &&
    (ans == -1 || ((long)ans * ans <= x && ans < l))
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