#include <stdlib.h>

/*@
    requires seed >= 0;
    requires seed <= 30; // prevent left-shift overflow in the specification
    assigns \nothing;
    ensures \result == 1 || \result == (1 << (seed-1));
*/
int evenBinomialCoeffSum(int seed);

int evenBinomialCoeffSum(int seed) {

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
		/*@
		    loop invariant 1 <= d <= seed+1;
		    loop invariant temp[0] == 1;
		    loop invariant \forall integer k; 1 <= k < d ==> temp[k] == (1 << (k-1));
		    loop assigns d, temp[0..seed];
		    loop variant seed - d + 1;
		*/
		for (int d = 1; d <= seed; d++) {
			/*@
			    loop invariant 0 <= c <= d;
			    loop assigns c, temp[0..seed];
			    loop variant d - c;
			*/
			for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
		}
		return temp[seed];
}
