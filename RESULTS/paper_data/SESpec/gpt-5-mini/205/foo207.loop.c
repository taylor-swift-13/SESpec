
/*@
  // Helper: count of occurrences of a given value v in a slice [lo,hi)
  logic integer count_eq_int{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 : count_eq_int(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0 .. args_len-1)) || args_len == 0;
  requires \valid(arr + (0 .. arr_len-1)) || arr_len == 0;
  requires args_len >= 0;
  requires arr_len >= 0;
  assigns \nothing;
*/
int foo207(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int len = 0;
		
        /*@
          loop invariant 0 <= ret <= args_len;
          loop invariant 0 <= len <= arr_len;
          loop invariant \exists integer i; 0 <= i < ret ==> (\exists integer j; 0 <= j < len && args[i] == arr[j]) || (\forall integer k; 0 <= k < len ==> args[i] != arr[k]);
          loop invariant \forall integer v; count_eq_int(args, 0, ret, v) == count_eq_int(arr, 0, len, v) + (count_eq_int(args, 0, ret, v) - count_eq_int(arr, 0, len, v));
          loop invariant (ret == args_len || len == arr_len) ==> (ret <= args_len && len <= arr_len);
          loop invariant ret + len >= 0;
          
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret >= 0 && len >= 0);
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret <= \at(args_len,Pre) && len <= \at(arr_len,Pre));
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (\forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre));
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre));
          
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((len == 0)&&(ret == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          
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
