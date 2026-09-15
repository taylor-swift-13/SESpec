#include <stdlib.h>

/*@
    requires count >= 0;
    requires m > 0;
    requires count + 1 <= INT_MAX / sizeof(int); // Ensure no overflow in memory allocation
    ensures \result >= 0;
    assigns \nothing;
*/
int countNoOfWays(int count, int m);

int countNoOfWays(int count, int m) {

		int w = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
		/*@
		    requires div != \null;
		    ensures \valid(div + (0..count));
		*/
		int div_len = count + 1;
		div[0] = 1;
		div[1] = m;
		div[2] = m * m;
		/*@
		    loop invariant 3 <= d <= count;
		    loop invariant \forall integer i; 0 <= i < d ==> div[i] >= 0;
		    loop assigns d, div[3..count];
		    loop variant count - d;
		*/
		for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
		int result = div[count];
		free(div);
		return result;
}
