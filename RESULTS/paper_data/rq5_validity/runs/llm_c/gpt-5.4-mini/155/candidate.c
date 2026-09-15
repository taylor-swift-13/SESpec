#include <stdlib.h>

/*@
    requires Array > 0;
    requires \valid_read(args + (0 .. Array - 1));
    assigns \nothing;
    ensures \result >= args[0];
*/
int maxProduct(int * args, int args_len, int Array);

int maxProduct(int * args, int args_len, int Array) {
		int *mpis = (int *)malloc(sizeof(int) * (Array));
        int mpis_len = Array;
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
        /*@
            loop invariant 1 <= i <= Array;
            loop invariant \valid(mpis + (0 .. Array - 1));
            loop invariant \valid_read(args + (0 .. Array - 1));
            loop assigns i, mpis[0 .. Array - 1];
            loop variant Array - i;
        */
		for (int i = 1; i < Array; i++) {
            /*@
                loop invariant 0 <= k <= i;
                loop invariant \valid(mpis + (0 .. Array - 1));
                loop invariant \valid_read(args + (0 .. Array - 1));
                loop assigns k, mpis[0 .. Array - 1];
                loop variant i - k;
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
            loop invariant \valid(mpis + (0 .. Array - 1));
            loop invariant num >= mpis[0];
            loop invariant \forall integer j; 0 <= j < i ==> num >= mpis[j];
            loop assigns i, num;
            loop variant Array - i;
        */
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
}
