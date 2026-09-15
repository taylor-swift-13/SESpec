#include <stddef.h>

/*@
    requires arr == \null || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures arr == \null ==> \result == -1;
    ensures arr != \null && arr_len == 1 ==> \result == 0;
*/
int findEvenPair(int * arr, int arr_len, int n);

 /*@
    requires arr == \null || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures arr == \null ==> \result == -1;
    ensures arr != \null && arr_len == 1 ==> \result == 0;
*/
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
		    loop assigns i, evenPairCount, c, pair, odd, even;
		    loop variant arr_len - i;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@
			    loop invariant i + 1 <= c <= arr_len;
			    loop invariant evenPairCount >= 0;
			    loop assigns c, evenPairCount, pair, odd, even;
			    loop variant arr_len - c;
			*/
			for (int c = i + 1; c < arr_len; c++) {
				int pair = arr[i];
				int odd = arr[c];
				int even = pair ^ odd;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
}
