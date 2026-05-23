#include <stdlib.h>

int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c);

/*@
    requires 0 <= Array <= arr1_len;
    requires 0 <= n <= arr_len;
    requires 0 <= c <= Array + n;
    requires Array == 0 || \valid(arr1 + (0 .. Array-1));
    requires n == 0 || \valid(arr + (0 .. n-1));
    assigns \nothing;
    behavior return_minus_one:
        assumes c == 0;
        ensures \result == -1;
    behavior return_element:
        assumes 1 <= c <= Array + n;
        ensures \exists integer i, j;
            0 <= i <= Array && 0 <= j <= n && i + j == c &&
            (
                (i > 0 && (j == 0 || arr1[i-1] <= arr[j-1]) ==> \result == arr1[i-1])
                &&
                (j > 0 && (i == 0 || arr[j-1] < arr1[i-1]) ==> \result == arr[j-1])
            );
    complete behaviors return_minus_one, return_element;
    disjoint behaviors return_minus_one, return_element;
*/
int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

		int result = 0;
		int tmp = 0;

		/*@
		    loop invariant 0 <= result <= Array;
		    loop invariant 0 <= tmp <= n;
		    loop invariant 0 <= count <= c;
		    loop invariant result + tmp == count;
		    loop variant c - count;
		    loop assigns result, tmp, count;
		*/
		for (int count = 0; count < c; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == c - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == c - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
}
