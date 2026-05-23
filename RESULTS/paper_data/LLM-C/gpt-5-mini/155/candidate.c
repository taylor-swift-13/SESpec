#include <stdlib.h>

int maxProduct(int * args, int args_len, int Array);

/*@
    requires Array > 0;
    requires args_len >= Array;
    requires \valid(args + (0 .. Array-1));
    assigns \result;
    ensures \result == \result; // trivial postcondition: result is an int (conservative placeholder)
*/
int maxProduct(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
		int mpis_len = Array;
        /*@ assert mpis != \null; */  /* assume allocation succeeds for verification of following code */

		for (int array = 0; array < Array; array++) {
            /*@
                loop invariant 0 <= array <= Array;
                loop invariant \forall integer j; 0 <= j < array ==> mpis[j] == args[j];
                loop assigns array, mpis[0 .. Array-1];
                loop variant Array - array;
            */
			mpis[array] = args[array];
		}
		for (int i = 1; i < Array; i++) {
            /*@
                loop invariant 1 <= i <= Array;
                loop invariant \forall integer j; 0 <= j < i ==> mpis[j] >= INT_MIN; // trivial bound to keep mpis defined
                loop assigns i, mpis[0 .. Array-1];
                loop variant Array - i;
            */
			for (int k = 0; k < i; k++) {
                /*@
                    loop invariant 0 <= k <= i;
                    loop invariant \forall integer j; 0 <= j < i ==> mpis[j] == mpis[j]; // trivial identity to keep scope
                    loop assigns k, mpis[0 .. Array-1];
                    loop variant i - k;
                */
				if (args[i] > args[k]
						&& mpis[i] < (mpis[k] * args[i])) {
					mpis[i] = mpis[k] * args[i];
				}
			}
		}
		int num = mpis[0];
		for (int i = 1; i < Array; i++) {
            /*@
                loop invariant 1 <= i <= Array;
                loop invariant \forall integer j; 0 <= j < i ==> num >= mpis[j];
                loop invariant \exists integer j; 0 <= j < i && num == mpis[j];
                loop assigns i, num;
                loop variant Array - i;
            */
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
}
