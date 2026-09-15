#include <stddef.h>

int findEvenPair(int * arr, int arr_len, int n);

/*@
    requires arr == \null || (arr_len >= 0 && \valid(arr + (0 .. arr_len-1)));
    assigns \nothing;
    behavior null_arr:
        assumes arr == \null;
        ensures \result == -1;
    behavior valid_arr:
        assumes arr != \null;
        ensures \result >= 0;
        ensures arr_len <= 1 ==> \result == 0;
        ensures arr_len >= 2 ==> \result <= (arr_len*(arr_len-1))/2;
    complete behaviors null_arr, valid_arr;
    disjoint behaviors null_arr, valid_arr;
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
		    loop invariant 0 <= evenPairCount <= (arr_len*(arr_len-1))/2;
		    loop assigns i, evenPairCount;
		    loop variant arr_len - i;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@
			    loop invariant i+1 <= c <= arr_len;
			    loop invariant 0 <= evenPairCount <= (arr_len*(arr_len-1))/2;
			    loop assigns c, evenPairCount;
			    loop variant arr_len - c;
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
