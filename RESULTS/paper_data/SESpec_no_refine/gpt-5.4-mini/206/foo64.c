
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
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
  assigns ret, r;
  ensures (ret < \old(args_len)) ==> \result == ret;
  ensures (ret >= \old(args_len)) ==> \result == r;
  ensures args == \old(args);
  ensures arr == \old(arr);
  ensures args_len == \old(args_len);
  ensures arr_len == \old(arr_len);
  ensures array == \old(array);
  ensures \forall integer i; 0 <= i < args_len ==> args[i] == \old(args[i]);
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \old(arr[i]);
  ensures \result >= 0;
  ensures \result <= \old(args_len);
  ensures \result <= \old(arr_len);
*/
int foo64(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= ret <= \at(args_len,Pre));
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (0 <= r <= \at(arr_len,Pre));
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((r == 0)&&(ret == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
          loop invariant \forall integer i; 0 <= i < args_len ==> args[i] == \at(args[i], Pre);
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
