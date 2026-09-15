int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p);

/*@ 
  requires 0 <= arr1_len;
  requires 0 <= arr_len;
  requires 0 <= Array <= arr1_len;
  requires 0 <= n <= arr_len;
  requires (Array == 0) || \valid_read(arr1 + (0 .. Array - 1));
  requires (n == 0) || \valid_read(arr + (0 .. n - 1));
  requires \separated(arr1 + (0 .. Array - 1), arr + (0 .. n - 1));
  requires 1 <= p <= Array + n;

  // Each input array is sorted in non-decreasing order over the used range.
  requires \forall integer i; 0 <= i && i + 1 < Array ==> arr1[i] <= arr1[i+1];
  requires \forall integer i; 0 <= i && i + 1 < n ==> arr[i] <= arr[i+1];

  assigns \nothing;

  // The result is an element taken from one of the two arrays.
  ensures (\exists integer i; 0 <= i < Array && \result == \at(arr1[i], Pre))
       || (\exists integer j; 0 <= j < n && \result == \at(arr[j], Pre));

  // Order-statistic characterization of the p-th element in the merged multiset:
  // The number of elements strictly less than the result is at most p-1,
  // and the number of elements less than or equal to the result is at least p.
  ensures ((\numof integer i; 0 <= i < Array && \at(arr1[i], Pre) < \result)
         + (\numof integer j; 0 <= j < n && \at(arr[j], Pre) < \result)) <= p - 1;

  ensures ((\numof integer i; 0 <= i < Array && \at(arr1[i], Pre) <= \result)
         + (\numof integer j; 0 <= j < n && \at(arr[j], Pre) <= \result)) >= p;
*/
int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int tmp = 0;

		/*@
		  loop invariant 0 <= count <= p;
		  loop invariant 0 <= result <= Array;
		  loop invariant 0 <= tmp <= n;
		  loop invariant result + tmp == count;
		  loop invariant (Array == 0) || \valid_read(arr1 + (0 .. Array - 1));
		  loop invariant (n == 0) || \valid_read(arr + (0 .. n - 1));
		  loop variant p - count;
		*/
		for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
}
