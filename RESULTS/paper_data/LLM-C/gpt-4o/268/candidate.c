#include <stdlib.h>

/*@
    requires count >= 0;
    requires w >= 0;
    requires \valid(\result);
    ensures \result >= 0;
    assigns \nothing;
*/
int countNoOfWays(int count, int w);

/*@
    requires count >= 0;
    requires w >= 0;
    requires \valid(\result);
    ensures \result >= 0;
    assigns \nothing;
*/
int countNoOfWays(int count, int w) {

		int result = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		for (int d = 3; d <= count; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % result;
		}
		return div[count];
}
