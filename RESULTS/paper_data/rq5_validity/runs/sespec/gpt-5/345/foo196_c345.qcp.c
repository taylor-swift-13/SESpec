#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo196_c345(int n);

int foo196_c345(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum=0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i >= 2) &&
((i <= n) => (i >= 2 && i <= n)) &&
(sum == even_div_sum_upto(n, i-1)) &&
((i > n) => (sum == even_div_sum_upto(n, n))) &&
(n == n@pre
          loop assigns i, sum)
    */
    
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                if(i%2==0)
                    sum+=i;
            }
        }
        return sum;
}