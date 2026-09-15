#include <stdlib.h>

/*@ 
    logic integer lucas(integer n) = 
        n == 0 ? 2 : n == 1 ? 1 : lucas(n-1) + lucas(n-2);
*/

/*@
    requires num >= 1;
    assigns \nothing;
    ensures \result == lucas(num);
*/
int findLucas(int num) {

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
		/*@
		    loop invariant 2 <= l <= num + 1;
		    loop invariant \forall integer k; 0 <= k < l ==> result[k] == lucas(k);
		    loop assigns l, result[0 .. num];
		    loop variant num - l + 1;
		*/
		for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[num];
}
