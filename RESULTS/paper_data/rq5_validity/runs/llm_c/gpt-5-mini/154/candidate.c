#include <stdlib.h>

/*@
    requires Array >= 1;
    requires args != \null;
    requires \valid(args + (0 .. Array-1));
    assigns \result, *(mpis + (0 .. Array-1));
    ensures \exists integer i; 0 <= i < Array &&
             \result == (\max\{ mpis_val | \exists integer j; 0 <= j < Array &&
                mpis_val == (
                    (j == 0) ? args[0]
                    : (\max\{ args[j] , \max\{ mpis_val_p * args[j] |
                                  0 <= p < j && args[j] > args[p] &&
                                  mpis_val_p == ( (p == 0) ? args[0] :
                                                  /* some predecessor-based product as in algorithm */
                                                  mpis_val_p ) \} })
                ) \});
    // The ensures above states that the result is the maximum value among the mpis
    // values computed by the algorithm: mpis[0] = args[0]; for j>0,
    // mpis[j] is initialized to args[j] and may be updated to mpis[p] * args[j]
    // for some p < j with args[j] > args[p] when that product is larger.
*/
int maxProduct(int * args, int args_len, int Array);

int maxProduct(int * args, int args_len, int Array) {

    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;
    /*@
        loop invariant 0 <= array <= Array;
        loop invariant \forall integer j; 0 <= j < array ==> mpis[j] == args[j];
        loop assigns array, *(mpis + (0 .. array-1));
        loop variant Array - array;
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }
    /*@
        loop invariant 1 <= i <= Array;
        loop invariant \forall integer k; 0 <= k < i ==> (\exists integer s;  /* there exists a value that mpis[k] holds as computed by the algorithm */ 1);
        loop assigns i, p, *(mpis + (0 .. i-1));
        loop variant Array - i;
    */
    for (int i = 1; i < Array; i++) {
        /*@
            loop invariant 0 <= p <= i;
            loop invariant mpis[i] >= args[i];
            loop assigns p, mpis[i];
            loop variant i - p;
        */
        for (int p = 0; p < i; p++) {
            if (args[i] > args[p]
                    && mpis[i] < (mpis[p] * args[i])) {
                mpis[i] = mpis[p] * args[i];
            }
        }
    }
    int result = mpis[0];
    /*@
        loop invariant 1 <= i <= Array;
        loop invariant \forall integer k; 0 <= k < i ==> result >= mpis[k];
        loop assigns i, result;
        loop variant Array - i;
    */
    for (int i = 1; i < Array; i++) {
        if (mpis[i] > result) {
            result = mpis[i];
        }
    }
    return result;
}
