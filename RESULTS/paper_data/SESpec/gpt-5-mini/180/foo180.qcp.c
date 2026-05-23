#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (same_array : Z -> Z -> Z -> Prop) */
int foo180(int * rot, int rot_len, int count) 
/*@
With rot_l
Require store_int_array(rot, rot_len, rot_l)
Ensure Results(__return)
*/{

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
	
 	/*@ Inv
    exists  rot_l,    
    store_int_array(rot, rot_len, rot_l) &&
    (0 <= r) &&
    (top <= count@pre - 1) &&
    ((r == 0) || (r <= top)) &&
    (count == count@pre) &&
    (rot_len == rot_len@pre) &&
    (rot == rot@pre) &&
    (same_array{Pre,Here}(rot, 0, rot_len)) &&
    ((0 < count@pre - 1) => (((top == count@pre - 1) && (r == 0)) || (r < top => rot_l[r] >= rot_l[top])))
    */
while (r < top) {
			if (rot[r] < rot[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			if (rot[i] > rot[r]) {
				r = i;
			} else {
				top = i;
			}
		}
		return r + 1;
}