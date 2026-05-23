#include <stdlib.h>

/*@ 
    requires b >= 0;
    requires \valid_range((int *)malloc(sizeof(int) * (b + 1)), 0, b);
    assigns \nothing;
    ensures \result >= 0;
*/
int evenBinomialCoeffSum(int b);

int evenBinomialCoeffSum(int b) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
int arr_len = b + 1;
		arr[0] = 1;
		/*@
		    loop invariant 1 <= d <= b + 1;
		    loop assigns d, arr[1..b];
		    loop variant b - d + 1;
		*/
		for (int d = 1; d <= b; d++) {
		    /*@
		        loop invariant 0 <= c <= d;
		        loop assigns c, arr[d];
		        loop variant d - c;
		    */
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[b];
}
