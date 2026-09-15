#include <stdlib.h>

/*@
    requires count >= 1;
    assigns \nothing;
    ensures \result >= 0;
*/
int countWays(int count);

int countWays(int count) {

		int *w = (int *)malloc(sizeof(int) * (count + 1));
int w_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
		/*@
		    loop invariant 2 <= index <= count + 1;
		    loop invariant w[0] == 1 && w[1] == 0 && C[0] == 0 && C[1] == 1;
		    loop invariant \forall integer j; 2 <= j < index ==> (w[j] == w[j-2] + 2 * C[j-1] && C[j] == w[j-1] + C[j-2]);
		    loop assigns index, w[0..count], C[0..count];
		    loop variant count - index + 1;
		*/
		for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
		return w[count];
}
