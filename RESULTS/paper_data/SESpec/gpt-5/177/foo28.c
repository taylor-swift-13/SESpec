
/*@
  // Array is not modified by the loop (read-only usage in this function).
  predicate unchanged{L1,L2}(int *a, integer lo, integer hi) =
    \forall integer k; lo <= k < hi ==> \at(a[k], L1) == \at(a[k], L2);
*/

/*@
  // Convenience: count how many entries equal v in a prefix [0,hi)
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires arr_len >= 0;
  requires \valid_read(arr + (0..arr_len-1));
  requires \forall integer k1, k2; 0 <= k1 <= k2 < arr_len ==> arr[k1] <= arr[k2];
  assigns \nothing;
  ensures arr == \at(arr,Pre) && arr_len == \at(arr_len,Pre) && array == \at(array,Pre);
  ensures unchanged{Pre,Here}(arr, 0, arr_len);
  ensures \result == -1 || (0 <= \result < arr_len);
  ensures (\result != -1 ==> arr[\result] == array && (\result == arr_len - 1 || arr[\result + 1] != array));
  ensures (\result != -1 ==> arr[\result] == array);
  ensures \result == -1 || \result == arr_len - 1 || arr[\result + 1] != array;
  ensures \result == -1 || arr[\result] == array || 0 == 1;
  ensures \result == -1 || (\forall integer k; 0 <= k < arr_len ==> arr[k] <= array || arr[k] >= array);
  ensures \result == -1 || \true;
  ensures \result == \result;
*/
int foo28(int * arr, int arr_len, int array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant arr == \at(arr,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant 0 <= arr_len;
          loop invariant 0 <= i <= arr_len;
          loop invariant -1 <= hi < arr_len;
          loop invariant i <= hi + 1;
          loop invariant (\forall integer k; 0 <= k < i ==> arr[k] <= array);
          loop invariant (\forall integer k; hi + 1 <= k < arr_len ==> arr[k] >= array);
          loop invariant (i <= hi ==> 0 <= end < arr_len);
          loop invariant unchanged{Pre,Here}(arr, 0, arr_len);
          loop assigns end, i, hi;
        */
        while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
            
		return -1;
}
