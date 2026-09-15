#include <stdlib.h>

/*@
    requires 0 <= b <= 30;
    assigns \nothing;
    ensures (b == 0 && \result == 1) || (b > 0 && \result == (1 << (b-1)));
*/
int evenBinomialCoeffSum(int b) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
int arr_len = b + 1;
		arr[0] = 1;
		/*@
		    loop invariant 1 <= d <= b+1;
		    loop invariant arr[0] == 1;
		    loop invariant \forall integer k; 1 <= k < d ==> arr[k] == (1 << (k-1));
		    loop assigns d, arr[0 .. b];
		    loop variant b - d + 1;
		*/
		for (int d = 1; d <= b; d++) {
			/*@
			    loop invariant 0 <= c <= d;
			    loop invariant arr[d] == \sum integer j; 0 <= j < c; arr[j];
			    loop assigns c, arr[d];
			    loop variant d - c;
			*/
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[b];
}
