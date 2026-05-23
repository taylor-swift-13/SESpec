#include <stdlib.h>

int maxProduct(int * args, int args_len, int Array);

/*@
  requires Array >= 1;
  requires args_len >= Array;
  requires \valid(args + (0..Array-1));
  ensures \forall integer i; 0 <= i < Array ==> \result >= args[i];
  ensures \forall integer i; 0 <= i < Array ==> args[i] == \at(args[i], Pre);
  ensures Array == 1 ==> \result == args[0];
*/
int maxProduct(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
int mpis_len = Array;
    /*@ assert mpis != \null; */
    /*@ assert \valid(mpis + (0..Array-1)); */
		/*@
		  loop invariant 0 <= array <= Array;
		  loop invariant \valid(mpis + (0..Array-1));
		  loop invariant \forall integer j; 0 <= j < array ==> mpis[j] == args[j];
		  loop assigns mpis[0..Array-1], array;
		  loop variant Array - array;
		*/
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		/*@
		  loop invariant 1 <= i <= Array;
		  loop invariant \valid(mpis + (0..Array-1));
		  loop invariant \forall integer t; 0 <= t < i ==> mpis[t] >= args[t];
		  loop assigns mpis[0..Array-1], i;
		  loop variant Array - i;
		*/
		for (int i = 1; i < Array; i++) {
			/*@
			  loop invariant 0 <= k <= i;
			  loop invariant mpis[i] >= args[i];
              loop assigns mpis[i], k;
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
        /*@ assert num == mpis[0]; */
		/*@
		  loop invariant 1 <= i <= Array;
		  loop invariant \forall integer t; 0 <= t < i ==> num >= mpis[t];
		  loop invariant \exists integer u; 0 <= u < i && num == mpis[u];
		  loop assigns num, i;
		  loop variant Array - i;
		*/
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
}
