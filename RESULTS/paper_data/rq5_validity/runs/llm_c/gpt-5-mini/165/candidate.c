#include <stddef.h>

int findEvenPair(int * arr, int arr_len, int n);

/*@
    requires arr == \null || arr_len <= 0 || \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    behavior null_arr:
        assumes arr == \null;
        ensures \result == -1;
    behavior single_len:
        assumes arr != \null && arr_len == 1;
        ensures \result == 0;
    behavior general:
        assumes arr != \null && arr_len > 1;
        ensures \result == \sum integer a; 0 <= a < arr_len;
                           \sum integer b; a+1 <= b < arr_len;
                               (((arr[a] ^ arr[b]) & 1) == 0 ? 1 : 0);
    complete behaviors null_arr, single_len, general;
    disjoint behaviors null_arr, single_len, general;
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
		    loop invariant evenPairCount == \sum integer a; 0 <= a < i;
		                               \sum integer b; a+1 <= b < arr_len;
		                                   (((arr[a] ^ arr[b]) & 1) == 0 ? 1 : 0);
		    loop assigns i, evenPairCount, c;
		    loop variant arr_len - i;
		*/
		for (int i = 0; i < arr_len; i++) {
			/*@
			    loop invariant i+1 <= c <= arr_len;
			    loop invariant evenPairCount == 
			        \sum integer a; 0 <= a < i;
			            \sum integer b; a+1 <= b < arr_len;
			                (((arr[a] ^ arr[b]) & 1) == 0 ? 1 : 0)
			      + \sum integer b; i+1 <= b < c;
			                (((arr[i] ^ arr[b]) & 1) == 0 ? 1 : 0);
			    loop assigns c, evenPairCount;
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
