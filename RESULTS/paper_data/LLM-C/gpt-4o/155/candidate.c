#include <stdlib.h>

/*@
    requires \valid(args+(0..args_len-1));
    requires args_len >= Array;
    requires Array > 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int maxProduct(int * args, int args_len, int Array);

int maxProduct(int * args, int args_len, int Array) {

    /*@
        requires Array > 0;
        allocates \result;
        ensures \valid(\result+(0..Array-1));
    */
    int *mpis = (int *)malloc(sizeof(int) * (Array));
    int mpis_len = Array;

    /*@
        loop invariant 0 <= array <= Array;
        loop invariant \valid(mpis+(0..Array-1));
        loop invariant \forall integer i; 0 <= i < array ==> mpis[i] == args[i];
        loop assigns array, mpis[0..Array-1];
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }

    /*@
        loop invariant 1 <= i <= Array;
        loop invariant \valid(mpis+(0..Array-1));
        loop assigns i, k, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {
        /*@
            loop invariant 0 <= k <= i;
            loop invariant \valid(mpis+(0..Array-1));
            loop assigns k, mpis[i];
        */
        for (int k = 0; k < i; k++) {
            if (args[i] > args[k]
                    && mpis[i] < (mpis[k] * args[i])) {
                mpis[i] = mpis[k] * args[i];
            }
        }
    }

    int num = mpis[0];

    /*@
        loop invariant 1 <= i <= Array;
        loop invariant \valid(mpis+(0..Array-1));
        loop invariant \forall integer j; 0 <= j < i ==> num >= mpis[j];
        loop assigns i, num;
    */
    for (int i = 1; i < Array; i++) {
        if (mpis[i] > num) {
            num = mpis[i];
        }
    }

    free(mpis);
    return num;
}
