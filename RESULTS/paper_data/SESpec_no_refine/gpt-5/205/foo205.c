
/*@
  predicate unchanged_array{L1,L2}(int *a, integer lo, integer hi) =
    \forall integer k; lo <= k < hi ==> \at(a[k],L1) == \at(a[k],L2);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures args == \at(args,Pre);
  ensures args_len == \at(args_len,Pre);
  ensures arr == \at(arr,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures Array == \at(Array,Pre);
  ensures \result == (\result < args_len ? \result : \result);
*/
int foo205(int * args, int args_len, int * arr, int arr_len, int Array) {

		int ret = 0;
		int len = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= ret <= \at(args_len,Pre));
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= len <= \at(arr_len,Pre));
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((len == 0)&&(ret == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant unchanged_array{Here,Pre}(arr, 0, \at(arr_len,Pre)) ;
          loop invariant unchanged_array{Here,Pre}(args, 0, \at(args_len,Pre)) ;
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
