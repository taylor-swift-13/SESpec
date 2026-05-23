#include <stdlib.h>

/*@ 
    logic integer pell(integer n) =
        n == 0 ? 0 :
        n == 1 ? 1 :
        (2 * pell(n-1) + pell(n-2)) % 1000000000;
*/

/*@
    requires seed >= 1;
    ensures \result == pell(seed);
    assigns \nothing;
*/
int getPell(int seed) {

		int *p = (int *)malloc(sizeof(int) * (seed + 1));
		int p_len = seed + 1;
		/*@ assume p != \null && \valid(p + (0 .. p_len-1)); */
		p[0] = 0;
		p[1] = 1;
		/*@
		    loop invariant 2 <= count <= seed+1;
		    loop invariant \forall integer j; 0 <= j < count ==> p[j] == pell(j);
		    loop assigns count, p[2..seed];
		    loop variant seed - count + 1;
		*/
		for (int count = 2; count <= seed; count++) {
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
		}
		return p[seed];
}
