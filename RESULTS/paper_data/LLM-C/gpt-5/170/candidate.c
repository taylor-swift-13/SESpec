/*@ predicate strictly_increasing{L}(int *a, integer n) =
      n <= 1 ||
      (\forall integer i; 0 <= i < n-1 ==> a[i] < a[i+1]);

    predicate rotated_strict_inc{L}(int *a, integer n, integer p) =
      n >= 1 && 0 <= p < n &&
      (
        (p == 0 && strictly_increasing(a, n)) ||
        (p > 0 &&
           (\forall integer i; 0 <= i < p-1 ==> a[i] < a[i+1]) &&
           a[p-1] > a[p] &&
           (\forall integer i; p <= i < n-1 ==> a[i] < a[i+1])
        )
      );

    predicate is_rotated_strict_inc{L}(int *a, integer n) =
      n >= 1 && (\exists integer p; 0 <= p < n && rotated_strict_inc(a, n, p));

    predicate is_min_index{L}(int *a, integer n, integer k) =
      0 <= k < n && (\forall integer i; 0 <= i < n ==> a[k] <= a[i]);
*/

/*@ requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;

    ensures arr_len == 0 ==> \result == 0;
    ensures arr_len > 0 ==> 0 <= \result < arr_len;

    ensures arr_len <= 1 ==> \result == 0;

    ensures (arr_len >= 1 && rotated_strict_inc(arr, arr_len, 0)) ==> \result == 0;

    ensures (arr_len >= 2 && is_rotated_strict_inc(arr, arr_len)) ==>
              rotated_strict_inc(arr, arr_len, \result) &&
              is_min_index(arr, arr_len, \result);
*/
int findRotationCount(int * arr, int arr_len);

int findRotationCount(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		/*@ loop invariant 0 <= ret <= arr_len;
		    loop invariant -1 <= stop < arr_len || arr_len == 0;
		    loop invariant ret <= stop + 1;
		    loop assigns ret, stop;
		    loop variant (stop - ret + 1);
		*/
		while (ret <= stop) {
			int r = ret + (stop - ret) / 2;
			/*@ assert ret <= r <= stop; */
			if (r < stop
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				stop = r - 1;
			}
		}
		return 0;
}
