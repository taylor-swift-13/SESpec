#include <stdlib.h>

int maxProduct(int * args, int args_len, int Array);

/*@ 
  requires Array >= 1;
  requires args_len >= 0;
  requires Array <= args_len;
  requires \valid_read(args + (0..Array-1));
  requires \initialized(args + (0..Array-1));
  ensures \exists integer j; 0 <= j < Array && \result == \at(mpis[j], \Post);
  ensures \forall integer i; 0 <= i < Array ==> \at(mpis[i], \Post) <= \result;
  ensures \forall integer i; 0 <= i < Array ==> \at(mpis[i], \Post) >= args[i];
*/
int maxProduct(int * args, int args_len, int Array) {

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
		  loop invariant \forall integer j; 0 <= j < i ==> mpis[j] >= args[j];
		  loop invariant mpis[i] >= args[i];
		  loop assigns mpis[0..Array-1];
		  loop variant Array - i;
		*/
		for (int i = 1; i < Array; i++) {
			/*@
			  loop invariant 0 <= p <= i;
			  loop invariant \valid(mpis + (0..Array-1));
			  loop invariant \forall integer j; 0 <= j < i ==> mpis[j] >= args[j];
			  loop invariant mpis[i] >= args[i];
			  loop assigns mpis[i];
			  loop variant i - p;
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
		  loop invariant \forall integer k; 0 <= k < i ==> num >= mpis[k];
		  loop invariant \exists integer t; 0 <= t < i && num == mpis[t];
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
