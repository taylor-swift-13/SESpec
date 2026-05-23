#include <stdlib.h>

/*@
    requires count >= 2;
    requires w >= 0;
    requires \valid((int *)malloc(sizeof(int) * (count + 1)));
    assigns \nothing;
    ensures \result == \old(\result);
*/
int countNoOfWays(int count, int w);



/*@ 
    requires count >= 2;
    requires w >= 0;
    requires \valid((int *)malloc(sizeof(int) * (count + 1)));
    assigns \nothing;
    ensures \result >= 0;
*/
int countNoOfWays(int count, int w) {

		int result = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
		/*@
		    loop invariant 3 <= d <= count + 1;
		    loop invariant \valid(div + (0 .. count));
		    loop invariant div[0] == 1;
		    loop invariant div[1] == w;
		    loop invariant div[2] == w * w;
		    loop assigns d, div[3 .. count];
		    loop variant count - d + 1;
		*/
		for (int d = 3; d <= count; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % result;
		}
		return div[count];
}
