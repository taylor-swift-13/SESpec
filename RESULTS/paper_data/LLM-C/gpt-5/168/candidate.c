/*@ predicate inc_segment{L}(int *a, integer l, integer u) =
      \forall integer i; l <= i < u ==> a[i] < a[i+1];

    predicate rotation_pivot{L}(int *a, integer n, integer p) =
      n >= 2 && 0 <= p < n &&
      (p == 0 ?
         inc_segment(a, 0, n-1)
       :
         inc_segment(a, 0, p-2) && a[p-1] > a[p] && inc_segment(a, p, n-2));

    predicate rotated_strict_increasing{L}(int *a, integer n) =
      n <= 1 || (\exists integer p; rotation_pivot(a, n, p));
*/

int findRotationCount(int * arr, int arr_len);

/*@ requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    requires arr_len <= 1 || rotated_strict_increasing(arr, arr_len);
    assigns \nothing;
    ensures arr_len == 0 ==> \result == 0;
    ensures arr_len > 0 ==> 0 <= \result < arr_len;
    ensures arr_len <= 1 ==> \result == 0;
    ensures arr_len >= 2 && rotated_strict_increasing(arr, arr_len) ==>
            (\exists integer p; rotation_pivot(arr, arr_len, p) && \result == p);
    ensures arr_len >= 1 && (arr_len <= 1 || rotated_strict_increasing(arr, arr_len)) ==>
            (\forall integer i; 0 <= i < arr_len ==> (i == \result || arr[\result] < arr[i]));
*/
int findRotationCount(int * arr, int arr_len) {

		int ret = 0;
		int count = arr_len - 1;
		/*@ loop invariant 0 <= ret <= arr_len;
		    loop invariant -1 <= count <= arr_len - 1;
		    loop invariant ret <= count + 1;
		    loop assigns ret, count;
		    loop variant count - ret + 1;
		*/
		while (ret <= count) {
			int r = ret + (count - ret) / 2;
			/*@ assert ret <= r; */
			/*@ assert r <= count; */
			/*@ assert 0 <= r; */
			/*@ assert 0 <= ret < arr_len; */
			/*@ assert 0 <= r < arr_len; */
			if (r < count
					&& arr[r] > arr[r + 1]) {
				/*@ assert r < count ==> 0 <= r+1 < arr_len; */
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				/*@ assert r > ret ==> 0 <= r-1 < arr_len; */
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				count = r - 1;
			}
		}
		return 0;
}
