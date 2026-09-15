
/*@ 
  predicate unchanged_array(int *a, int *init_a, integer len) =
    \forall integer k; 0 <= k < len ==> a[k] == init_a[k];
*/

/*@
  logic integer max_prefix(int *a, integer lo, integer hi) =
    lo >= hi ? 0
    : (hi == lo + 1 ? a[lo]
       : (max_prefix(a, lo, hi - 1) >= a[hi - 1] ? max_prefix(a, lo, hi - 1) : a[hi - 1]));
*/

/*@
  logic integer min_prefix(int *a, integer lo, integer hi) =
    lo >= hi ? 0
    : (hi == lo + 1 ? a[lo]
       : (min_prefix(a, lo, hi - 1) <= a[hi - 1] ? min_prefix(a, lo, hi - 1) : a[hi - 1]));
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid(arr + (0 .. \at(arr_len,Pre) - 1));
  assigns \nothing;   
  ensures arr == \at(arr,Pre) && arr_len == \at(arr_len,Pre) && 
          unchanged_array(arr, \at(arr,Pre), \at(arr_len,Pre));
  ensures \result == max_prefix(arr, 0, arr_len) - min_prefix(arr, 0, arr_len);
*/
int foo94(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		
            
        /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant result == max_prefix(arr, 0, n);
          loop invariant sum == min_prefix(arr, 0, n);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array(arr, \at(arr,Pre), \at(arr_len,Pre));
          loop assigns n, result, sum;
        */
        for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
            
		return result - sum;
}
