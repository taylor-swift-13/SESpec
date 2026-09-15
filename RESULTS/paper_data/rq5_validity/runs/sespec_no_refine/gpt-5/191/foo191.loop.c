
#include <stdlib.h>

int foo191(int count) {

    int *W = (int *)malloc(sizeof(int) * (count + 1));
    int W_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;
    W[0] = 1;
    W[1] = 0;
    C[0] = 0;
    C[1] = 1;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant 2 <= w <= count + 1;
      loop invariant W_len == count + 1 && C_len == count + 1;
      loop invariant \valid(W + (0..count)) && \valid(C + (0..count));
      loop invariant W[0] == 1 && W[1] == 0;
      loop invariant C[0] == 0 && C[1] == 1;
      loop invariant \forall integer k; 2 <= k < w ==> (W[k] == W[k-2] + 2 * C[k-1] && C[k] == W[k-1] + C[k-2]);
      loop assigns w, W[..], C[..];
    */
    for (int w = 2; w <= count; w++) {
        W[w] = W[w - 2]
                + 2 * C[w - 1];
        C[w] = W[w - 1] + C[w - 2];
    }
            
    return W[count];
}
