#include <stdlib.h>

/*@
    requires seed >= 1;
    requires \valid((int *)malloc(sizeof(int) * (seed + 1)));
    assigns \nothing;
    ensures \result >= 0;
*/
int getPell(int seed);

int getPell(int seed) {

		int *p = (int *)malloc(sizeof(int) * (seed + 1));
int p_len = seed + 1;
		p[0] = 0;
		p[1] = 1;
		/*@
		    loop invariant 2 <= count <= seed + 1;
		    loop invariant \valid(p + (0 .. seed));
		    loop invariant p[0] == 0;
		    loop invariant p[1] == 1;
		    loop invariant \forall integer i; 2 <= i < count ==> p[i] == ((2 * p[i - 1] + p[i - 2]) % 1000000000);
		    loop assigns count, p[2 .. seed];
		    loop variant seed - count + 1;
		*/
		for (int count = 2; count <= seed; count++) {
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
		}
		return p[seed];
}
