#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo367(int n);

int foo367(int n) 
/*@

Require emp
Ensure (exists i_56, i_56 > __return / i_56 && 2 <= i_56 && (forall j_48, 2 <= j_48 && j_48 < i_56 => __return % j_48 != 0)) || (n % __return == 0 && __return <= n / __return && 2 <= __return && (forall j_48, 2 <= j_48 && j_48 < __return => n % j_48 != 0))
*/
{

        int i = 2;
       
  /*@ Inv
    (2 <= i) &&
    (forall (j:Z), 2 <= j && j < i => n % j != 0)
    */
while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
}