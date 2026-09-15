#include <stddef.h>

/*@
    requires arr != \null;
    requires arr_len >= 0;
    requires \valid_read(arr + (0..arr_len-1));
    ensures \result >= 0;
    ensures \result == -1 <==> arr == \null;
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
		loop invariant \forall integer x, y; 0 <= x < i && x < y < arr_len ==> 
			((arr[x] ^ arr[y]) & 1) == 0 ==> evenPairCount >= 1;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@
			loop invariant i + 1 <= c <= arr_len;
			loop invariant evenPairCount >= 0;
			loop assigns c, evenPairCount;
			loop invariant \forall integer x, y; 0 <= x < i && x < y < c ==> 
				((arr[x] ^ arr[y]) & 1) == 0 ==> evenPairCount >= 1;
			*/
			for (int c = i + 1; c < arr_len; c++) {
				int odd = arr[i];
				int b = arr[c];
				int even = odd ^ b;
				if ((even & 1) == 0) {
					evenPairCount++;
				}
			}
		}
		return evenPairCount;
}
