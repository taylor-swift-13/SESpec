#include <stddef.h>

int findEvenPair(int * arr, int arr_len, int n);

/*@
    requires \true;
    behavior null_arr:
        assumes arr == \null;
        ensures \result == -1;
        assigns \nothing;
    behavior non_null:
        assumes arr != \null && arr_len >= 0 && (arr_len == 0 || \valid(arr + (0 .. arr_len-1)));
        ensures \result == (\sum integer i; 0 <= i < arr_len; \sum integer j; i < j < arr_len; (((arr[i] ^ arr[j]) & 1) == 0 ? 1 : 0));
        assigns \nothing;
    complete behaviors null_arr, non_null;
    disjoint behaviors null_arr, non_null;
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
		    loop invariant 0 <= i && i <= arr_len;
		    loop invariant evenPairCount == (\sum integer ii; 0 <= ii < i; \sum integer jj; ii < jj < arr_len; (((arr[ii] ^ arr[jj]) & 1) == 0 ? 1 : 0));
		    loop assigns i, evenPairCount;
		    loop variant arr_len - i;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@ 
			    loop invariant i+1 <= c && c <= arr_len;
			    loop invariant evenPairCount == (\sum integer ii; 0 <= ii < i; \sum integer jj; ii < jj < arr_len; (((arr[ii] ^ arr[jj]) & 1) == 0 ? 1 : 0))
			                         + (\sum integer jj; i < jj < c; (((arr[i] ^ arr[jj]) & 1) == 0 ? 1 : 0));
			    loop assigns c, evenPairCount;
			    loop variant arr_len - c;
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
