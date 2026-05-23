#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo367(int n);

int foo367(int n) 
/*@

Require emp
Ensure (exists i_53, i_53 > n / i_53 && 2 <= i_53 && (forall j_47, 2 <= j_47 && j_47 < i_53 => n % j_47 != 0) && (2 <= n / 2 => i_53 > 1) && (2 <= n / 2 => 2 <= i_53) && (!(2 <= n / 2) => i_53 == 2 && n == n) && __return == n) || (n % __return == 0 && __return <= n / __return && 2 <= __return && (forall j_47, 2 <= j_47 && j_47 < __return => n % j_47 != 0) && (2 <= n / 2 => __return > 1) && (2 <= n / 2 => 2 <= __return) && (!(2 <= n / 2) => __return == 2 && n == n))
*/
{

        int i = 2;
       
  /*@ Inv
    (2 <= i) &&
    (n == n@pre) &&
    (forall (j:Z), 2 <= j && j < i => n % j != 0) &&
    ((2 <= n@pre / 2) => (i > 1)) &&
    ((2 <= n@pre / 2) => (2 <= i)) &&
    ((!(2 <= n@pre / 2)) => ((i == 2)&&(n == n@pre)))
    */
while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
}