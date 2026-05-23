#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo352(int number);

int foo352(int number) 
/*@

Require emp
Ensure (exists ret_68 total_67 result_66, total_67 <= 0 && 0 <= ret_68 && total_67 == number >> ret_68 && (forall k_53, 0 <= k_53 && k_53 < ret_68 => (k_53 % 2 == 0 => (result_66 & 1 << k_53) != 0) && (k_53 % 2 != 0 => (result_66 & 1 << k_53) == 0)) && (forall k_54, k_54 >= ret_68 => (result_66 & 1 << k_54) == 0) && (ret_68 == 0 => result_66 == 0) && __return == (number ^ result_66))
*/
{

		int result = 0;
		int ret = 0;
		int total = number;
	
 	/*@ Inv
    (0 <= ret) &&
    (number == number@pre) &&
    (total == (number@pre >> ret)) &&
    ((forall (k:Z), 0 <= k && k < ret => ( (k % 2 == 0) => ((result & (1 << k)) != 0) ) && ( (k % 2 != 0) => ((result & (1 << k)) == 0) ))) &&
    ((forall (k:Z), k >= ret => ((result & (1 << k)) == 0))) &&
    ((ret == 0) => (result == 0))
    */
while (total > 0) {
        if (ret % 2 == 0) {
            result = result | (1 << ret);
        }
        ret++;
        total >>= 1;
    }
		return number ^ result;
}