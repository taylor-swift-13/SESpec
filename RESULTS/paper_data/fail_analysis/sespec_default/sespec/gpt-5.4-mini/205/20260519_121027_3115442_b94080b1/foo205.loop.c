
/*@
  logic integer count_args_less(int* args, integer lo, integer hi, int x) =
    lo >= hi ? 0
             : count_args_less(args, lo, hi - 1, x) + (args[hi - 1] < x ? 1 : 0);

  logic integer count_arr_less(int* arr, integer lo, integer hi, int x) =
    lo >= hi ? 0
             : count_arr_less(arr, lo, hi - 1, x) + (arr[hi - 1] < x ? 1 : 0);

  logic integer count_args_equal(int* args, integer lo, integer hi, int x) =
    lo >= hi ? 0
             : count_args_equal(args, lo, hi - 1, x) + (args[hi - 1] == x ? 1 : 0);

  logic integer count_arr_equal(int* arr, integer lo, integer hi, int x) =
    lo >= hi ? 0
             : count_arr_equal(arr, lo, hi - 1, x) + (arr[hi - 1] == x ? 1 : 0);
*/

int foo205(int * args, int args_len, int * arr, int arr_len, int Array) {

		int ret = 0;
		int len = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret <= \at(args_len,Pre) && len <= \at(arr_len,Pre) && ret >= 0 && len >= 0);
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((len == 0)&&(ret == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer i; 0 <= i < \at(args_len,Pre) ==> args[i] == \at(args[i],Pre);
          loop invariant \forall integer i; 0 <= i < \at(arr_len,Pre) ==> arr[i] == \at(arr[i],Pre);
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
