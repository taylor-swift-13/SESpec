
#include <stdlib.h>

/*@ logic integer recN(int* N, integer i) =
      i <= 0 ? 2 :
      i == 1 ? 1 :
      recN(N, i - 1) + 2 * recN(N, i - 2);
*/

int foo290(int c) {

		int *N = (int *)malloc(sizeof(int) * (c + 1));
int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
		
            
        /*@
          loop invariant 2 <= p;
          loop invariant N[0] == 2;
          loop invariant N[1] == 1;
          loop invariant \forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2];
          loop assigns p, N[0 .. c];
        */
            for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
            
		return N[c];
}
