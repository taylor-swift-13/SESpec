
/*@
  logic integer unchanged_array(int *arr, integer n) =
    0;
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures (0 <= \old(arr_len) - 1) ==> ((0 <= \result < \old(arr_len)) && ((\result < \old(arr_len) - 1) ==> \old(arr[\result]) > \old(arr[\result + 1])) && ((\result > 0) ==> \old(arr[\result]) < \old(arr[\result - 1])));
  ensures (0 <= \old(arr_len) - 1) ==> (\result == 0 || (0 <= \result < \old(arr_len)));
  ensures !(0 <= \old(arr_len) - 1) ==> \result == 0;
*/
int foo21(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		
            
        /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((stop == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= ret <= \at(arr_len,Pre) && stop < \at(arr_len,Pre)));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((stop == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (-1 <= stop < \at(arr_len,Pre)));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((stop == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer i; 0 <= i < \at(arr_len,Pre) ==> arr[i] == \at(arr[i],Pre);
          loop assigns r, ret, stop;
            */
            while (ret <= stop) {
			int r = ret + (stop - ret) / 2;
			if (r < stop
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				stop = r - 1;
			}
		}
            
		return 0;
}
