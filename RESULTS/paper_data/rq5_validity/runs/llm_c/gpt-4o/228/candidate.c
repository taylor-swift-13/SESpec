#include <stdlib.h>

/*@
    requires seed >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int evenBinomialCoeffSum(int seed);

int evenBinomialCoeffSum(int seed) {

		int result = 0;
		/*@
		    requires seed >= 0;
		    ensures \valid(temp + (0..seed));
		    assigns temp[0..seed];
		*/
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
		int temp_len = seed + 1;
		temp[0] = 1;
		/*@
		    loop invariant 0 <= d <= seed;
		    loop assigns d,temp;
		*/
		for (int d = 1; d <= seed; d++) {
			/*@
			    loop invariant 0 <= c <= d;
			    loop assigns c,temp;
			*/
			for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
		}
		return temp[seed];
}
