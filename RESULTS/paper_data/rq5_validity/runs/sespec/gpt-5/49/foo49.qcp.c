#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo49(int i, int j, int k) 
/*@

Require emp
Ensure emp
*/{

    int n;
    int b;

    n = 0;
    b = 1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= n) &&
    (n <= 2 * k) &&
    (b == 0 || b == 1) &&
    ((b == 1) <=> (n % 2 == 0)) &&
    (i + j == i@pre + j@pre + n) &&
    (i == i@pre + (n + 1) / 2) &&
    (j == j@pre + n / 2) &&
    (i >= i@pre) &&
    (j >= j@pre) &&
    ((n % 2 == 0) => (i - i@pre == j - j@pre)) &&
    ((n % 2 == 1) => (i - i@pre == (j - j@pre) + 1)) &&
    ((n == 0) => (b == 1 && i == i@pre && j == j@pre)) &&
    ((n == 2 * k) => (b == ( (2 * k) % 2 == 0 ? 1 : 0 ))) &&
    ((n >= 1) => ( (b == 0 && i == i@pre + (n + 1)/2 && j == j@pre + n/2) || (b == 1 && i == i@pre + n/2 && j == j@pre + n/2) )) &&
    ((0 < (2 * k@pre)) => (i + j == i@pre + j@pre + n)) &&
    ((0 < (2 * k@pre)) => ( (0 <= i - i@pre) && (i - i@pre == (n + 1) / 2) )) &&
    ((0 < (2 * k@pre)) => ( (0 <= j - j@pre) && (j - j@pre == n / 2) )) &&
    ((0 < (2 * k@pre)) => ( 0 <= n && n <= 2 * k@pre )) &&
    ((0 < (2 * k@pre)) => (((b == 1)&&(n == 0)&&(k == k@pre)&&(j == j@pre)&&(i == i@pre)) || (b == 0 || b == 1))) &&
    ((!(0 < (2 * k@pre))) => ((b == 1)&&(n == 0)&&(k == k@pre)&&(j == j@pre)&&(i == i@pre))) &&
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