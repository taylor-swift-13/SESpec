
/*@
  logic integer count_occ{L}(int *a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 : count_occ(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo207(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int len = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret >= 0 && ret <= \at(args_len,Pre) && len >= 0 && len <= \at(arr_len,Pre) && ret + len <= \at(args_len,Pre) + \at(arr_len,Pre));
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret <= \at(args_len,Pre) && len <= \at(arr_len,Pre)) ;
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret + len <= \at(args_len,Pre) + \at(arr_len,Pre)) ;
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((len == 0)&&(ret == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop assigns ret, len;
            */
            while (ret < args_len && len < arr_len) {
			if (args[ret] < arr[len]) {
				ret++;
			} else if (args[ret] > arr[len]) {
				len++;
			} else {
				ret++;
				len++;
			}
		}
            
		return ret < args_len ? ret : len;
}
