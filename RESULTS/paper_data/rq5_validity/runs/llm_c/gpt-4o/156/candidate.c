#include <stdlib.h>

/*@
    requires \valid_read(args + (0..args_len-1));
    requires args_len >= Array && Array > 0;
    ensures \result >= 0;
    assigns \nothing;
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
    */
    for (int array = 0; array < Array; array++) {
        mpis[array] = args[array];
    }

    /*@
        loop invariant 1 <= i <= Array;
        loop invariant \valid(mpis + (0..Array-1));
        loop invariant \forall integer k; 0 <= k < i ==> 
            \forall integer p; 0 <= p < k ==> 
                (args[k] > args[p] && mpis[k] >= mpis[p] * args[k]) || mpis[k] == args[k];
        loop assigns i, p, mpis[0..Array-1];
    */
    for (int i = 1; i < Array; i++) {
        /*@
            loop invariant 0 <= p <= i;
            loop invariant \valid(mpis + (0..Array-1));
            loop invariant \forall integer k; 0 <= k < p ==> 
                (args[i] > args[k] && mpis[i] >= mpis[k] * args[i]) || mpis[i] == args[i];
            loop assigns p, mpis[i];
        */
        for (int p = 0; p < i; p++) {
            if (args[i] > args[p]
                    && mpis[i] < (mpis[p] * args[i])) {
                mpis[i] = mpis[p] * args[i];
            }
        }
    }

    int num = mpis[0];
    /*@
        loop invariant 1 <= i <= Array;
        loop invariant \valid(mpis + (0..Array-1));
        loop invariant num == \max(mpis[0..i-1]);
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
