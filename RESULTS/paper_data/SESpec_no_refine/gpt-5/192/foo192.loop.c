
#include <stdlib.h>

int foo192(int count) {

		int *w = (int *)malloc(sizeof(int) * (count + 1));
int w_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= index <= count + 1;
              loop invariant w_len == count + 1 && C_len == count + 1;
              loop invariant \valid(w + (0 .. w_len-1)) && \valid(C + (0 .. C_len-1));
              loop invariant w[0] == 1 && w[1] == 0;
              loop invariant C[0] == 0 && C[1] == 1;
              loop invariant \forall integer k; 2 <= k < index ==> w[k] == w[k - 2] + 2 * C[k - 1];
              loop invariant \forall integer k; 2 <= k < index ==> C[k] == w[k - 1] + C[k - 2];
              loop assigns index, w[..], C[..];
            */
            for (int index = 2; index <= count; index++) {
			w[index] = w[index - 2]
					+ 2 * C[index - 1];
			C[index] = w[index - 1] + C[index - 2];
		}
            
		return w[count];
}
