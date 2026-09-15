
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
  
  ensures args_len == \old(args_len);
  ensures arr_len == \old(arr_len);
  ensures Array == \old(Array);
  ensures args == \old(args);
  ensures arr == \old(arr);
  ensures \forall integer i; 0 <= i < args_len ==> args[i] == \old(args[i]);
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \old(arr[i]);
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
