#include <stdlib.h>

/*@
    requires count >= 2;
    assigns \nothing;
    logic integer D(integer m, integer d) =
        d == 0 ? 1
        : d == 1 ? m
        : d == 2 ? m*m
        : ((m - 1) * (D(m, d-1) + D(m, d-2))) mod 1000000007;
    ensures \result == D(m, count);
    ensures 0 <= \result < 1000000007;
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
		    loop invariant \forall integer k; 0 <= k < d ==> div[k] == D(m, k);
		    loop assigns d, div[3..count];
		    loop variant count - d + 1;
		*/
		for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
		return div[count];
}
