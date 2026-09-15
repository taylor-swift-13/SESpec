#include <stddef.h>

int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p);

/*@ 
  requires Array >= 0;
  requires n >= 0;
  requires 1 <= p <= Array + n;

  // memory validity for read accesses
  requires Array == 0 || \valid_read(arr1 + (0 .. Array-1));
  requires n == 0 || \valid_read(arr + (0 .. n-1));

  // arrays are sorted in non-decreasing order
  requires \forall integer i, j; 0 <= i <= j < Array ==> arr1[i] <= arr1[j];
  requires \forall integer i, j; 0 <= i <= j < n ==> arr[i] <= arr[j];

  assigns \nothing;

  // result is the p-th element (1-based) of the merged non-decreasing sequence
  ensures \result != -1;
  ensures 
    \let r = \result;
    (\numof integer i; 0 <= i < Array && arr1[i] < r)
    + (\numof integer j; 0 <= j < n && arr[j] < r) < p
    &&
    (\numof integer i; 0 <= i < Array && arr1[i] <= r)
    + (\numof integer j; 0 <= j < n && arr[j] <= r) >= p;
*/
int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int s = 0;

		/*@
		  loop invariant 0 <= count <= p;
		  loop invariant 0 <= result <= Array;
		  loop invariant 0 <= s <= n;
		  loop invariant result + s == count;
		  loop assigns result, s, count;
		  loop variant p - count;
		*/
		for (int count = 0; count < p; count++) {
			if (result < Array
					&& (s >= n || arr1[result] <= arr[s])) {
				/*@ assert result < Array; */
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				/*@ assert s < n; */
				if (count == p - 1) {
					return arr[s];
				}
				s++;
			}
		}
		return -1;
}
