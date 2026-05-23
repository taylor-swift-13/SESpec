
/*@
  logic integer count_args_lt(int *args, integer lo, integer hi, int x) =
    lo >= hi ? 0
             : count_args_lt(args, lo, hi - 1, x) + (args[hi - 1] < x ? 1 : 0);

  logic integer count_arr_lt(int *arr, integer lo, integer hi, int x) =
    lo >= hi ? 0
             : count_arr_lt(arr, lo, hi - 1, x) + (arr[hi - 1] < x ? 1 : 0);
*/

/*@ 
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo64(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret <= \at(args_len,Pre) && r <= \at(arr_len,Pre)) ;
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret + r <= \at(args_len,Pre) + \at(arr_len,Pre)) ;
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((r == 0)&&(ret == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant ret >= 0;
          loop invariant r >= 0;
          loop invariant \forall integer i; 0 <= i < args_len ==> args[i] == \at(args[i],Pre);
          loop invariant \forall integer j; 0 <= j < arr_len ==> arr[j] == \at(arr[j],Pre);
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
