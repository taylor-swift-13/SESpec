#include <stddef.h>

/*@
    requires arr != NULL ==> \valid_read(arr+(0..arr_len-1));
    requires arr_len >= 0;
    ensures \result >= -1;
    ensures arr == NULL ==> \result == -1;
    ensures arr_len == 1 ==> \result == 0;
    assigns \nothing;
*/
int findEvenPair(int * arr, int arr_len, int n);

int findEvenPair(int * arr, int arr_len, int n) {

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
		/*@
		    loop invariant 0 <= i <= arr_len;
		    loop invariant evenPairCount >= 0;
		    loop assigns i, evenPairCount;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@
			    loop invariant i + 1 <= c <= arr_len;
			    loop invariant evenPairCount >= 0;
			    loop assigns c, evenPairCount;
			*/
			for (int c = i + 1; c < arr_len; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
}
