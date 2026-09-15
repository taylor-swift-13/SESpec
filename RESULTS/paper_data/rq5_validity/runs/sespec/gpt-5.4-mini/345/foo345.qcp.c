#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (evendiv_sum : Z -> Z -> Z) */
int foo345(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum=0;
       
  /*@ Inv
    (2 <= i) &&
    (0 <= sum) &&
    ((i<=n@pre) => (sum == evendiv_sum(n, i - 1))) &&
    ((i<=n@pre) => (0 <= sum)) &&
    ((!(i<=n@pre)) => (sum == evendiv_sum(n, n@pre))) &&
    (n == n@pre) &&
    (forall (k:Z), 2 <= k && k < i => (n % k == 0 && k % 2 == 0) => sum >= k) &&
    (sum > 0 => exists (k:Z), 2 <= k && k < i && n % k == 0 && k % 2 == 0)
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