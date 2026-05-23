/*@ 
  logic integer count_lt{L}(int *a, integer len, integer v) =
    \numof integer i; 0 <= i < len && a[i] < v;

  logic integer count_le{L}(int *a, integer len, integer v) =
    \numof integer i; 0 <= i < len && a[i] <= v;
*/

/*@ 
  requires Array >= 0 && n >= 0;
  requires 1 <= c <= Array + n;
  requires Array == 0 || \valid_read(arr1 + (0 .. Array-1));
  requires n == 0 || \valid_read(arr + (0 .. n-1));
  requires \forall integer i, j; 0 <= i <= j < Array ==> arr1[i] <= arr1[j];
  requires \forall integer i, j; 0 <= i <= j < n ==> arr[i] <= arr[j];
  assigns \nothing;
  ensures \result != -1;
  ensures count_lt(arr1, Array, \result) + count_lt(arr, n, \result) <= c - 1;
  ensures count_le(arr1, Array, \result) + count_le(arr, n, \result) >= c;
  ensures (Array == 0) ==> (\result == arr[c-1]);
  ensures (n == 0) ==> (\result == arr1[c-1]);
*/
int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c);

int findKth(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

		int result = 0;
		int tmp = 0;

		/*@
		  loop invariant 0 <= count <= c;
		  loop invariant 0 <= result <= Array;
		  loop invariant 0 <= tmp <= n;
		  loop invariant result + tmp == count;
		  loop invariant (result >= Array) ==> (tmp < n);
		  loop invariant (tmp >= n) ==> (result < Array);
		  loop invariant \forall integer i1, i2; 0 <= i1 < result <= i2 < Array ==> arr1[i1] <= arr1[i2];
		  loop invariant \forall integer j1, j2; 0 <= j1 < tmp <= j2 < n ==> arr[j1] <= arr[j2];
		  loop assigns count, result, tmp;
		  loop variant c - count;
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
