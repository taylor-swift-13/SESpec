#include <stdlib.h>

/*@
    requires count >= 2;
    requires m >= 0;
    requires \valid((int *)malloc(sizeof(int) * (count + 1)));
    assigns \nothing;
    ensures \result >= 0;
*/
int countNoOfWays(int count, int m);

int countNoOfWays(int count, int m) {

		int w = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = m;
		div[2] = m * m;
		/*@
		    loop invariant 3 <= d <= count + 1;
		    loop assigns d, div[3..count];
		    loop variant count - d + 1;
		*/
		for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
		return div[count];
}
