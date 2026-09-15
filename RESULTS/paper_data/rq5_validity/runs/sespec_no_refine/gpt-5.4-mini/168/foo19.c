
/*@
  logic integer unchanged_array{L1,L2}(int *a, integer n) =
    \forall integer i; 0 <= i < n ==> a[i] == \at(a[i], L1);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures (\result == 0) ||
          (0 < \result && \result < arr_len && arr[\result - 1] > arr[\result]);
*/
int foo19(int * arr, int arr_len) {

		int ret = 0;
		int count = arr_len - 1;
		
        /*@
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((count == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= ret <= count + 1));
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (((count == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (ret <= count + 1));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((count == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre,Here}(arr, arr_len);
          loop assigns r, ret, count;
            */
            while (ret <= count) {
			int r = ret + (count - ret) / 2;
			if (r < count
					&& arr[r] > arr[r + 1]) {
				return r + 1;
			} else if (r > ret
					&& arr[r] < arr[r - 1]) {
				return r;
			}
			if (arr[r] >= arr[ret]) {
				ret = r + 1;
			} else {
				count = r - 1;
			}
		}
            
		return 0;
}
