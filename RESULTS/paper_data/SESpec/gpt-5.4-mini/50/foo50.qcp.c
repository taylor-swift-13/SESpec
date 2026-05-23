#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (parity : Z -> Z) */

void foo50(int i, int j, int k) 
/*@

Require emp
Ensure emp
*/{

    int n;
    int b;

    n = 0;
    b = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= n) &&
    (b == n % 2) &&
    (i + j == i@pre + j@pre + n) &&
    (i >= i@pre) &&
    (j >= j@pre) &&
    (0 <= b && b <= 1) &&
    (i@pre <= i && i <= i@pre + n) &&
    (j@pre <= j && j <= j@pre + n) &&
    (n == i + j - i@pre - j@pre) &&
    ((n % 2 == 0) => (b == 0)) &&
    ((n % 2 == 1) => (b == 1)) &&
    ((0 < (2 * k@pre)) => (b == n % 2)) &&
    ((0 < (2 * k@pre)) => (0 <= n)) &&
    ((0 < (2 * k@pre)) => (i@pre <= i && i <= i@pre + n)) &&
    ((0 < (2 * k@pre)) => (j@pre <= j && j <= j@pre + n)) &&
    ((0 < (2 * k@pre)) => (0 <= b && b <= 1)) &&
    ((!(0 < (2 * k@pre))) => ((b == 0)&&(n == 0)&&(k == k@pre)&&(j == j@pre)&&(i == i@pre))) &&
    (k == k@pre)
    */
    
            while(n < (2 * k)){
       n = n + 1;
       if(b == 1){
       b = 0;
       i = i + 1;
      }
       else{
       b = 1;
       j = j + 1;
      }
      }

  }