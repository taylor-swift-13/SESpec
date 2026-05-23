#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo391(int n);

int foo391(int n) 
/*@

Require emp
Ensure (exists i_60, __return > n && 1 <= i_60 && 1 <= __return && __return >= 1 && i_60 >= 1 && (forall k_50, 1 <= k_50 && k_50 <= i_60 - 1 => k_50 * k_50 == k_50 * k_50) && (1 <= n => __return > 0 && i_60 > 0) && (1 <= n => 1 <= i_60) && (1 <= n => __return == 1 && i_60 == 1 && n == n || __return == (i_60 - 1) * (i_60 - 1)) && (!(1 <= n) => __return == 1 && i_60 == 1 && n == n))
*/
{

        int i = 1;
        int square = 1;
       
  /*@ Inv
    (1 <= i) &&
    (1 <= square) &&
    (square >= 1 && i >= 1) &&
    (forall (k:Z), 1 <= k && k <= i-1 => ( (k*k) == (k * k) )) &&
    ((1 <= n@pre) => (square > 0 && i > 0)) &&
    ((1 <= n@pre) => (1 <= i)) &&
    ((1 <= n@pre) => (((square == 1)&&(i == 1)&&(n == n@pre)) || (square == (i-1)*(i-1)))) &&
    ((!(1 <= n@pre)) => ((square == 1)&&(i == 1)&&(n == n@pre))) &&
    (n == n@pre)
    */
while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}