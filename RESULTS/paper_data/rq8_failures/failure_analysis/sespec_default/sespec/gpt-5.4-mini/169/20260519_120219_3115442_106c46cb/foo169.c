
/*@
  predicate array_unchanged{L1, L2}(int *arr, integer n) =
    \forall integer k; 0 <= k < n ==> \at(arr[k], L1) == \at(arr[k], L2);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures 0 <= \result < arr_len;
  ensures \result > 0 ==> (\result < arr_len && arr[\result - 1] > arr[\result]);
*/
int foo169(int * arr, int arr_len) {

		int r = 0;
		int stop = arr_len - 1;
		
            /*@
          loop invariant 0 <= r <= arr_len;
          loop invariant -1 <= stop < arr_len;
          loop invariant r <= stop + 1;
          loop invariant array_unchanged{Pre,Here}(arr, arr_len);
          loop assigns r, stop;
            */
            while (r <= stop) {
			int i = r + (stop - r) / 2;
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
