
/*@
  logic integer prefix_max(int* a, integer hi) =
    hi <= 1 ? a[0]
            : (prefix_max(a, hi - 1) >= a[hi - 1] ? prefix_max(a, hi - 1) : a[hi - 1]);

  logic integer prefix_min(int* a, integer hi) =
    hi <= 1 ? a[0]
            : (prefix_min(a, hi - 1) <= a[hi - 1] ? prefix_min(a, hi - 1) : a[hi - 1]);
*/

int foo234(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (n < arr_len) ==> (big >= sum);
          loop invariant (!(n < arr_len)) ==> (big >= sum);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
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
