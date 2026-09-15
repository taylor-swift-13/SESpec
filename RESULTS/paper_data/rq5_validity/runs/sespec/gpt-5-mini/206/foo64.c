
/*@ 
  logic integer min_int(integer x, integer y) = x <= y ? x : y;
*/

/*@
  predicate unchanged_array(int *a, integer len, int *a_pre) =
    \forall integer i; 0 <= i < len ==> a[i] == a_pre[i];
*/

/*@
  requires args_len >= 0;
  requires arr_len >= 0;
  requires \valid(args + (0 .. args_len-1)) || args_len == 0;
  requires \valid(arr + (0 .. arr_len-1)) || arr_len == 0;
  assigns \nothing;
  ensures unchanged_array(args, args_len, \at(args,Pre));
  ensures unchanged_array(arr, arr_len, \at(arr,Pre));
  ensures 0 <= \result;
  ensures (\result <= \at(args_len,Pre) || \result <= \at(arr_len,Pre));
*/
int foo64(int * args, int args_len, int * arr, int arr_len, int array) {

		int ret = 0;
		int r = 0;
		
            
        /*@
          loop invariant 0 <= ret <= \at(args_len,Pre);
          loop invariant 0 <= r <= \at(arr_len,Pre);
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret == ret && ret == ret);
          loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (r == r && r == r);
          loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((r == 0)&&(ret == 0)&&(array == \at(array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant array == \at(array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant unchanged_array(args, args_len, \at(args,Pre));
          loop invariant unchanged_array(arr, arr_len, \at(arr,Pre));
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
