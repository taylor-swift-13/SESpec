#include <stddef.h>

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires \valid(arr + (0..arr_len-1));
    ensures \result >= 0;
    ensures \result == -1 <==> arr == \null;
    ensures arr_len == 1 ==> \result == 0;
    assigns \nothing;
*/
int findEvenPair(int * arr, int arr_len, int n);

int findEvenPair(int * arr, int arr_len, int n) {

		/*@
		    requires arr != \null;
		    requires arr_len >= 0;
		    requires \valid(arr + (0..arr_len-1));
		    ensures \result >= 0;
		    ensures \result == -1 <==> arr == \null;
		    ensures arr_len == 1 ==> \result == 0;
		    assigns \nothing;
		*/
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
		loop assigns i;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@
			loop invariant 0 <= c <= arr_len;
			loop invariant evenPairCount >= 0;
			loop assigns c;
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
