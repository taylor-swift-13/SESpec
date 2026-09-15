#include <stdlib.h>

/*@ 
  logic integer lucas(integer n) = 
    (n == 0 ? 2 : (n == 1 ? 1 : lucas(n-1) + lucas(n-2)));
*/

/*@
    requires seed >= 1;
    assigns \nothing;
    ensures \result == lucas(seed);
*/
int findLucas(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
		int result_len = seed + 1;
        /*@ 
            // We expect malloc to succeed for verification of subsequent accesses.
            // The following assertions describe the intended state after allocation.
            // They are here to document assumptions used by the loop invariants.
            assert result != \null;
            assert \valid(result + (0 .. result_len-1));
        */

		result[0] = 2;
		result[1] = 1;
		/*@
		    loop invariant 2 <= c <= seed + 1;
		    loop invariant \forall integer j; 0 <= j < c ==> result[j] == lucas(j);
		    loop assigns c, result[2 .. seed];
		    loop variant seed - c + 1;
		*/
		for (int c = 2; c <= seed; c++) {
			result[c] = result[c - 1]
					+ result[c - 2];
		}
		return result[seed];
}
