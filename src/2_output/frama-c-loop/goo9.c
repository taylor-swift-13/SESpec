
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        


int factorial9(int n) /*@

Require emp
Ensure Results(__return)
*/
{

  int i = 1;
  int f = 1;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= n@pre) => (1 <= i && i <= n + 1) ) &&
((1 <= n@pre) => (f == factorial(i - 1)) ) &&
((!(1 <= n@pre)) => ((f == 1)&&(i == 1)&&(n == n@pre))) &&
(n == n@pre)
    */
    
            while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
  return f;
}
void goo9() 
/*@

Require emp

Ensure emp
*/{
  int t = factorial9(5);
  
}