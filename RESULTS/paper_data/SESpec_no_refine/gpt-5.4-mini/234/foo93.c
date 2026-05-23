
/*@ logic integer arr_min_prefix(int* arr, integer n) =
      n <= 0 ? arr[0] : (arr[n - 1] < arr_min_prefix(arr, n - 1) ? arr[n - 1] : arr_min_prefix(arr, n - 1));
*/

/*@ logic integer arr_max_prefix(int* arr, integer n) =
      n <= 0 ? arr[0] : (arr[n - 1] > arr_max_prefix(arr, n - 1) ? arr[n - 1] : arr_max_prefix(arr, n - 1));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
*/
int foo93(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant big >= arr[0];
          loop invariant sum <= arr[0];
          loop assigns n, big, sum;
            */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > big) {
				big = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
            
		return big - sum;
}
