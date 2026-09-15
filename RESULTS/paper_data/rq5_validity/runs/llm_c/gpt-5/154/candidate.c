#include <stdlib.h>

int maxProduct(int * args, int args_len, int Array);

/*@ 
  requires Array >= 1;
  requires args_len == Array;
  requires \valid_read(args + (0 .. Array-1));
  assigns \nothing;
  ensures \forall integer k; 0 <= k < Array ==> \result >= args[k];
  ensures \exists integer k; 0 <= k < Array && \result == \at(mpis[k], \post);
  ensures \forall integer j; 0 <= j < Array ==> \at(mpis[j], \post) <= \result;
*/
int maxProduct(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
		/*@
		  loop invariant 0 <= array <= Array;
		  loop invariant mpis_len == Array;
		  loop invariant \valid(mpis + (0 .. Array-1));
		  loop invariant \forall integer k; 0 <= k < array ==> mpis[k] == args[k];
		  loop assigns array, mpis[0 .. Array-1];
		  loop variant Array - array;
		*/
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		/*@
		  loop invariant 1 <= i <= Array;
		  loop invariant \valid(mpis + (0 .. Array-1));
          loop invariant \forall integer j; 0 <= j < i ==> mpis[j] >= args[j];
		  loop assigns i, mpis[0 .. Array-1];
		  loop variant Array - i;
		*/
		for (int i = 1; i < Array; i++) {
			/*@
			  loop invariant 0 <= p <= i;
			  loop invariant \valid(mpis + (0 .. Array-1));
			  loop invariant mpis[i] >= args[i];
			  loop invariant \forall integer q; 0 <= q < p && args[i] > args[q] ==> mpis[i] >= mpis[q] * args[i];
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
