#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo357(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
        int res = 0;
        int temp = n;
       
  /*@ Inv
    (0 <= count) &&
    (temp == (n@pre >> count)) &&
    ((n@pre == 0) => (count == 0 && temp == 0 && res == 0)) &&
    ((n@pre > 0) => (0 <= count)) &&
    ((n@pre > 0) => (temp > 0 => (n@pre >> count) > 0)) &&
    ((n@pre > 0) => (temp == 0 => (n@pre >> count) == 0)) &&
    ((n@pre > 0) => (forall (k:Z), 0 <= k && k < count => ((k % 2 == 1) => (((res >> k) & 1) == 1)))) &&
    ((temp == 0) => ((n@pre >> count) == 0)) &&
    ((!(n@pre > 0)) => ((temp == n@pre)&&(res == 0)&&(count == 0)&&(n == n@pre))) &&
    (n == n@pre)
    */
while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
        return (n | res);
}