#include <stdlib.h>

/*@
    requires \valid(args + (0..args_len-1));
    requires args_len >= Array && Array > 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int maxProduct(int * args, int args_len, int Array);

int maxProduct(int * args, int args_len, int Array) {

    /*@
        requires Array > 0;
        ensures \valid(mpis + (0..Array-1));
        ensures mpis_len == Array;
        assigns mpis[0..Array-1];
    */
    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;

    /*@
        loop invariant 0 <= array <= Array;
        loop invariant \valid(mpis + (0..Array-1));
        loop invariant \forall integer k; 0 <= k < array ==> mpis[k] == args[k];
        loop assigns array, mpis[0..Array-1];
        loop variant Array - array;
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }

    /*@
        loop invariant 1 <= i <= Array;
        loop invariant \valid(mpis + (0..Array-1));
        loop assigns i, p, mpis[0..Array-1];
        loop variant Array - i;
    */
    for (int i = 1; i < Array; i++) {
        /*@
            loop invariant 0 <= p <= i;
            loop invariant \valid(mpis + (0..Array-1));
            loop assigns p, mpis[0..Array-1];
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
        loop invariant \valid(mpis + (0..Array-1));
        loop invariant result >= 0;
        loop assigns i, result;
        loop variant Array - i;
    */
    for (int i = 1; i < Array; i++) {
        if (mpis[i] > result) {
            result = mpis[i];
        }
    }

    free(mpis);
    return result;
}
