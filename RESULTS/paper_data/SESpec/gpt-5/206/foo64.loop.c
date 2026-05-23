
/*@
  logic integer count_lt(int* a, integer lo, integer hi, int v) =
    lo >= hi ? 0 : count_lt(a, lo, hi - 1, v) + (a[hi - 1] < v ? 1 : 0);
*/

/*@
  logic integer count_lt_val(int* a, integer lo, integer hi, int* b, integer j) =
    (j <= 0) ? 0 : count_lt(a, lo, hi, b[j-1]);
*/

int foo64(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant 0 <= r;
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop assigns ret, r;
            */
            while (ret < args_len && r < arr_len) {
			if (args[ret] < arr[r]) {
				ret++;
			} else if (args[ret] > arr[r]) {
				r++;
			} else {
				ret++;
				r++;
			}
		}
            
		return ret < args_len ? ret : r;
}
