#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo161(int * positions, int positions_len, int array);

int foo161(int * positions, int positions_len, int array) 
/*@
With positions_l
Require store_int_array(positions, positions_len, positions_l) && positions_len > 0 && positions_len < 100
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) && positions_len > 0 && positions_len < 100 &&
    (array == array@pre) &&
(positions_len == positions_len@pre) &&
(positions == positions@pre) &&
((0 < array@pre) => (ret <= array@pre)) &&
((0 < array@pre) => (ret >= 0)) &&
((0 < array@pre) => (ret == 0 || ret > 0)) &&
((!(0 < array@pre)) => ((ret == 0)&&(array == array@pre)&&(positions_len == positions_len@pre)&&(positions == positions@pre))
          loop assigns ret, positions_l[0..array-1])
    */
    
            while (ret < array) {
			if (positions[ret] <= 0 || positions[ret] > array
					|| positions[ret] == ret + 1) {
				ret++;
			} else {
				int j = positions[ret];
				positions[ret] = positions[j - 1];
				positions[j - 1] = j;
			}
		}
	
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    exists  positions_l,    
    store_int_array(positions, positions_len, positions_l) && positions_len > 0 && positions_len < 100 &&
    (0 <= ret) &&
(forall (k:Z), 0 <= k && k < ret => positions_l[k] == k + 1) &&
(positions == positions@pre
          loop assigns ret)
    */
    
            for (ret = 0; ret < array; ret++) {
			if (positions[ret] != ret + 1) {
				return ret + 1;
			}
		}
		return array + 1;
}