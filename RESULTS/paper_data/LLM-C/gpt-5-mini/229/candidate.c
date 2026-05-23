#include <stdlib.h>

/*@
    requires seed >= 0;
    assigns \nothing;
    ensures \true;
*/
int evenBinomialCoeffSum(int seed) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
		int arr_len = seed + 1;
		/*@ 
		    // If allocation succeeded, the array region is valid
		    ensures arr != \null ==> \valid(arr + (0 .. arr_len-1));
		*/
		arr[0] = 1;
		/*@
		    loop invariant 1 <= d <= seed+1;
		    loop invariant arr[0] == 1;
		    loop invariant \valid(arr + (0 .. arr_len-1));
		    loop assigns d, arr[1 .. arr_len-1];
		    loop variant seed - d + 1;
		*/
		for (int d = 1; d <= seed; d++) {
			/*@
			    loop invariant 0 <= c <= d;
			    loop invariant \valid(arr + (0 .. arr_len-1));
			    loop assigns c, arr[d];
			    loop variant d - c;
			*/
			for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[seed];
}
