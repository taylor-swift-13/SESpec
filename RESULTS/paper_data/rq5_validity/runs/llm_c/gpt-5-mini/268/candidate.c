#include <stdlib.h>

/*@
    requires count >= 2;
    requires w >= 0;
    logic integer MOD = 1000000007;
    logic integer D(integer k, integer ww) =
        (k == 0 ? 1
        : k == 1 ? ww
        : k == 2 ? ww * ww
        : ((ww - 1) * (D(k-1, ww) + D(k-2, ww))) % MOD);
    assigns \result;
    ensures 0 <= \result < MOD;
    ensures \result == (int)D(count, w);
*/
int countNoOfWays(int count, int w);

int countNoOfWays(int count, int w) {

		int result = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		/*@
		    loop invariant 3 <= d <= count + 1;
		    loop invariant \forall integer j; 0 <= j < d ==> div[j] == (int)D(j, w);
		    loop assigns d, div[0 .. count];
		    loop variant count - d + 1;
		*/
		for (int d = 3; d <= count; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % result;
		}
		return div[count];
}
