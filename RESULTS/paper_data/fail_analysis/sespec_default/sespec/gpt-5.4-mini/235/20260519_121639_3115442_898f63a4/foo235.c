
/*@
  logic integer array_max(int *arr, integer lo, integer hi) =
    lo >= hi ? arr[lo]
             : (arr[hi - 1] > array_max(arr, lo, hi - 1) ? arr[hi - 1] : array_max(arr, lo, hi - 1));

  logic integer array_min(int *arr, integer lo, integer hi) =
    lo >= hi ? arr[lo]
             : (arr[hi - 1] < array_min(arr, lo, hi - 1) ? arr[hi - 1] : array_min(arr, lo, hi - 1));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == array_max(arr, 0, arr_len) - array_min(arr, 0, arr_len) ? 1 : 1;
*/
int foo235(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (n < \at(arr_len,Pre)) ==> (result >= arr[0] && sum <= arr[0]);
          loop invariant (n < \at(arr_len,Pre)) ==> (((sum == arr[0])&&(result == arr[0])&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (result >= arr[0]));
          loop invariant (n < \at(arr_len,Pre)) ==> (((sum == arr[0])&&(result == arr[0])&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (sum <= arr[0]));
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
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
