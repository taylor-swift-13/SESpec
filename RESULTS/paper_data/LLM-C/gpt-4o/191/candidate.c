#include <stdlib.h>

/*@
    requires count >= 0;
    requires \valid(W+(0..count));
    requires \valid(C+(0..count));
    assigns W[0..count], C[0..count];
    ensures \forall integer w; 0 <= w <= count ==> W[w] >= 0 && C[w] >= 0;
    ensures \result == W[count];
*/
int countWays(int count) {

    int *W = (int *)malloc(sizeof(int) * (count + 1));
    int W_len = count + 1;
    int *C = (int *)malloc(sizeof(int) * (count + 1));
    int C_len = count + 1;

    W[0] = 1;
    W[1] = 0;
    C[0] = 0;
    C[1] = 1;

    /*@
        loop invariant 2 <= w <= count + 1;
        loop invariant \forall integer i; 0 <= i < w ==> W[i] >= 0 && C[i] >= 0;
        loop assigns w, W[2..count], C[2..count];
        loop variant count - w;
    */
    for (int w = 2; w <= count; w++) {
        W[w] = W[w - 2] + 2 * C[w - 1];
        C[w] = W[w - 1] + C[w - 2];
    }

    return W[count];
}
