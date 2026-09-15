
int foo205(int * args, int args_len, int * arr, int arr_len, int Array) {

		int ret = 0;
		int len = 0;
		
            
        /*@
          loop invariant args_len >= 0 ==> 0 <= ret <= args_len;
          loop invariant arr_len >= 0 ==> 0 <= len <= arr_len;
          loop invariant ret + len >= 0;
          loop invariant ret >= 0 && len >= 0;
          loop invariant (ret < args_len && len < arr_len) ==> ret + len < args_len + arr_len;
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= ret <= \at(args_len,Pre) && 0 <= len <= \at(arr_len,Pre));
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= ret <= args_len);
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= len <= arr_len);
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((len == 0)&&(ret == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
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
