
#include <stdlib.h>

int foo290(int c) {

		int *N = (int *)malloc(sizeof(int) * (c + 1));
int N_len = c + 1;
		N[0] = 2;
		N[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= p <= c + 1;
          loop invariant N_len == c + 1 && \valid(N + (0..N_len-1));
          loop invariant N[0] == 2 && N[1] == 1;
          loop invariant \forall integer k; 2 <= k < p ==> N[k] == N[k - 1] + 2 * N[k - 2];
          loop assigns p, N[..];
            */
            for (int p = 2; p <= c; p++) {
			N[p] = N[p - 1]
					+ 2 * N[p - 2];
		}
            
		return N[c];
}
