#include <stdlib.h>

/*@
    requires seed >= 1;
    assigns \nothing;
    ensures \result > 0;
*/
int findLucas(int seed);

 /*@
    requires seed >= 1;
    ensures \result > 0;
*/
int findLucas(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
		/*@
		    loop invariant 2 <= l <= seed + 1;
		    loop invariant result[0] == 2;
		    loop invariant result[1] == 1;
		    loop assigns l, result[2 .. seed];
		    loop variant seed - l + 1;
		*/
		for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[seed];
}
