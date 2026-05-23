#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (bitwise_or_accumulator : Z -> Z -> Z) */
int foo356(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int res = 0;
        int count = 0;
        int temp = n;
       
  /*@ Inv
    (temp >= 0) &&
    (count >= 0) &&
    (temp == n >> count) &&
    ((forall (k:Z), 0 <= k && k < count => (k % 2 == 0 => ((res & (1 << k)) != 0)))) &&
    ((!(n@pre > 0)) => ((temp == n@pre) && (count == 0) && (res == 0) && (n == n@pre)))
    */
while (temp > 0) {
        if (count % 2 == 0) {
            res = res | (1 << count);
        }
        count++;
        temp >>= 1;
    }
        return n ^ res;
}