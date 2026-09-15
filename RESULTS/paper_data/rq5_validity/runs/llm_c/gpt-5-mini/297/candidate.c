#include <stdlib.h>

/*@
  logic integer lucas(integer n) =
    n == 0 ? 2 :
    n == 1 ? 1 :
    lucas(n-1) + lucas(n-2);
*/

/*@
    requires seed >= 1;
    assigns \nothing;
    ensures \result == lucas(seed);
*/
int findLucas(int seed);

int findLucas(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
		/*@
		  loop invariant 2 <= l <= seed + 1;
		  loop invariant \forall integer j; 0 <= j < l ==> result[j] == lucas(j);
		  loop assigns l, result[2..seed];
		  loop variant seed - l + 1;
		*/
		for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[seed];
}
