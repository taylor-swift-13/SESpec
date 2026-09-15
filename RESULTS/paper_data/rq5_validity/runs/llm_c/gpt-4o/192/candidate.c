#include <stdlib.h>

/*@
    requires count >= 0;
    requires \valid((int *)malloc(sizeof(int) * (count + 1)));
    ensures \result >= 0;
    assigns \nothing;
*/
int countWays(int count);

int countWays(int count) {

    /*@
        requires count >= 0;
        requires \valid((int *)malloc(sizeof(int) * (count + 1)));
        ensures \result >= 0;
        assigns \nothing;
    */
		int *w = (int *)malloc(sizeof(int) * (count + 1));
int w_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
		for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
		return w[count];
}
