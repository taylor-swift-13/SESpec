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
    ((0 <= x@pre) => (ans == -1 || (long)ans * ans <= x@pre)) &&
((0 <= x@pre) => (((ans == -1)&&(r == x@pre)&&(l == 0)&&(x == x@pre)) || (0 <= l))) &&
((0 <= x@pre) => (((ans == -1)&&(r == x@pre)&&(l == 0)&&(x == x@pre)) || (r <= x@pre))) &&
((0 <= x@pre) => (((ans == -1)&&(r == x@pre)&&(l == 0)&&(x == x@pre)) || (ans >= -1))) &&
((!(0 <= x@pre)) => ((ans == -1)&&(r == x@pre)&&(l == 0)&&(x == x@pre))) &&
(x == x@pre)
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