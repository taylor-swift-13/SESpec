#include <stdlib.h>

/*@
    requires dim >= 2;
    requires w >= 0;
    requires \let n = dim + 1; n > 0;
    requires \valid(((int *)malloc(sizeof(int) * (dim + 1))));
    assigns \nothing;
    ensures \result >= 0;
*/
int countNoOfWays(int dim, int w);

int countNoOfWays(int dim, int w) {

		int count = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (dim + 1));
int div_len = dim + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		/*@
		    loop invariant 3 <= d <= dim + 1;
		    loop invariant \valid(div + (0 .. dim));
		    loop invariant div[0] == 1;
		    loop invariant div[1] == w;
		    loop invariant div[2] == w * w;
		    loop invariant \forall integer i; 3 <= i < d ==> div[i] == ((w - 1) * (div[i - 1] + div[i - 2])) % count;
		    loop assigns d, div[3 .. dim];
		    loop variant dim - d + 1;
		*/
		for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
		return div[dim];
}
