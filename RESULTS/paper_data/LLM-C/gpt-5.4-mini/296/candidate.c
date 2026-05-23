#include <stdlib.h>

/*@
    requires seed >= 1;
    assigns \nothing;
    ensures \result >= 1;
*/
int findLucas(int seed);

int findLucas(int seed) {

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
		/*@
		    loop invariant 2 <= c <= seed + 1;
		    loop invariant \valid(result + (0 .. seed));
		    loop invariant result[0] == 2;
		    loop invariant result[1] == 1;
		    loop invariant \forall integer i; 2 <= i < c ==> result[i] == result[i - 1] + result[i - 2];
		    loop assigns c, result[2 .. seed];
		    loop variant seed - c + 1;
		*/
		for (int c = 2; c <= seed; c++) {
			result[c] = result[c - 1]
					+ result[c - 2];
		}
		return result[seed];
}
