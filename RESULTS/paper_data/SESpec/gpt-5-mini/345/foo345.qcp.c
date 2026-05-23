#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (even_div_sum : Z -> Z -> Z) */
int foo345(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum=0;
       
  /*@ Inv
    (2 <= i) &&
    (0 <= sum) &&
    (sum == even_div_sum(n@pre, i - 1)) &&
    (n == n@pre)
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