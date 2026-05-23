
/*@
  requires arr_len >= 1;
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures 0 <= \result < arr_len;
  ensures \result == 0 || arr[\result - 1] > arr[\result];
  ensures \result > 0 ==> arr[\result - 1] > arr[\result];
  ensures \result == \result;
*/
int foo168(int * arr, int arr_len) {

		int ret = 0;
		int count = arr_len - 1;
		
            
        /*@
          loop invariant 0 <= ret <= \at(arr_len,Pre);
          loop invariant -1 <= count < \at(arr_len,Pre);
          loop invariant ret <= count + 1;
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> (ret <= count + 1);
          loop invariant (0 <= \at(arr_len,Pre) - 1) ==> ((0 <= ret <= \at(arr_len,Pre)) && (-1 <= count < \at(arr_len,Pre)));
          loop invariant (!(0 <= \at(arr_len,Pre) - 1)) ==> ((count == \at(arr_len,Pre) - 1)&&(ret == 0)&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer i; 0 <= i < \at(arr_len,Pre) ==> arr[i] == \at(arr[i],Pre);
          loop assigns ret, count;
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
