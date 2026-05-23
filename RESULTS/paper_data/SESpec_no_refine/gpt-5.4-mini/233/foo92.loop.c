
/*@ 
  logic integer arr_prefix_max(int* arr, integer lo, integer hi) =
    hi <= lo ? arr[lo] : (arr_prefix_max(arr, lo, hi - 1) > arr[hi - 1] ? arr_prefix_max(arr, lo, hi - 1) : arr[hi - 1]);

  logic integer arr_prefix_min(int* arr, integer lo, integer hi) =
    hi <= lo ? arr[lo] : (arr_prefix_min(arr, lo, hi - 1) < arr[hi - 1] ? arr_prefix_min(arr, lo, hi - 1) : arr[hi - 1]);
*/

int foo92(int * arr, int arr_len) {

		int result = arr[0];
		int num = arr[0];
		
        /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop assigns n, result, num;
        */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
            
		return result - num;
}
