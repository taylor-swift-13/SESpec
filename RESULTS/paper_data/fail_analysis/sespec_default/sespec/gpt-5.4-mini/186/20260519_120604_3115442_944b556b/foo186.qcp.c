#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo186(int size, int * a, int a_len);

int foo186(int size, int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

		if (size == 0) {
			return 0;
		}

		int f = a[0];
		int total = 1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    ((c < size@pre) => (f <= a_l[0])) &&
((c < size@pre) => (((total == 1)&&(f == a_l[0])&&(a_len == a_len@pre)&&(a == a@pre)&&(size == size@pre)) || (f <= a_l[0]@pre))) &&
((c < size@pre) => (((total == 1)&&(f == a_l[0])&&(a_len == a_len@pre)&&(a == a@pre)&&(size == size@pre)) || (total >= 1))) &&
(a_len == a_len@pre) &&
(a == a@pre) &&
(size == size@pre) &&
(forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre
          loop assigns c, f, total)
    */
    
            for (int c = 1; c < size; c++) {
			if (f > a[c]) {
				f = a[c];
				total = 1;
			} else if (f == a[c]) {
				total++;
			}
		}
		return total;
}