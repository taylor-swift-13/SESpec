#include <stdlib.h>

/*@
    logic integer D(integer d, integer w) =
        d == 0 ? 1
      : d == 1 ? w
      : d == 2 ? (w * w) % 1000000007
      : ((w - 1) * (D(d-1, w) + D(d-2, w))) % 1000000007;

    requires dim >= 0;
    assigns \nothing;
    ensures 0 <= \result < 1000000007;
    ensures \result == D(dim, w);
*/
int countNoOfWays(int dim, int w) {

		int count = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (dim + 1));
		int div_len = dim + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		/*@
		    loop invariant 3 <= d <= dim + 1;
		    loop invariant \forall integer k; 0 <= k < d ==> div[k] == D(k, w);
		    loop assigns d, div[3..dim];
		    loop variant dim - d + 1;
		*/
		for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
		return div[dim];
}
