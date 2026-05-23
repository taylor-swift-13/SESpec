int findRotationCount(int * arr, int arr_len);

/*@ predicate strictly_increasing_seq{L}(int *a, integer n) =
      n <= 1 || (\forall integer i; 0 <= i < n-1 ==> \at(a[i],L) < \at(a[i+1],L));

    predicate one_drop_increase{L}(int *a, integer n, integer b) =
      n >= 2 && 0 <= b < n-1 &&
      \at(a[b],L) > \at(a[b+1],L) &&
      (\forall integer i; 0 <= i < n-1 && i != b ==> \at(a[i],L) < \at(a[i+1],L));
*/

/*@ requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;

    ensures arr_len == 0 ==> \result == 0;
    ensures arr_len > 0 ==> 0 <= \result <= arr_len - 1;

    ensures arr_len > 0 && strictly_increasing_seq{Pre}(arr, arr_len) ==> \result == 0;

    ensures arr_len > 1 &&
            (\exists integer b; one_drop_increase{Pre}(arr, arr_len, b))
            ==> (\exists integer b; one_drop_increase{Pre}(arr, arr_len, b) && \result == b + 1);

    ensures arr_len > 0 &&
            ( strictly_increasing_seq{Pre}(arr, arr_len)
              || (\exists integer b; one_drop_increase{Pre}(arr, arr_len, b)) )
            ==> (\forall integer j; 0 <= j < arr_len ==> \at(arr[\result],Pre) <= \at(arr[j],Pre));
*/
int findRotationCount(int * arr, int arr_len) {

		int r = 0;
		int stop = arr_len - 1;
		/*@ loop invariant -1 <= stop <= arr_len - 1;
		    loop invariant 0 <= r <= arr_len;
		    loop invariant r <= stop + 1;
		    loop invariant r <= stop ==> (0 <= r && stop <= arr_len - 1);
		    loop assigns r, stop, i;
		    loop variant stop - r + 1;
		*/
		while (r <= stop) {
			int i = r + (stop - r) / 2;
			/*@ assert r <= i && i <= stop;
			    assert 0 <= r && (r <= stop ==> stop <= arr_len - 1);
			*/
			if (i < stop
					&& arr[i] > arr[i + 1]) {
				return i + 1;
			} else if (i > r
					&& arr[i] < arr[i - 1]) {
				return i;
			}
			if (arr[i] >= arr[r]) {
				r = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return 0;
}
