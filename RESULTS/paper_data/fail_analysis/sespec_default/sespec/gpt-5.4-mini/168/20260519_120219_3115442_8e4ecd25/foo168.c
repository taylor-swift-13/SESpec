

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures (0 <= \result < arr_len) ==> ((\result < arr_len - 1 && arr[\result] > arr[\result + 1]) || (\result > 0 && arr[\result] < arr[\result - 1]) || (\result == 0));
*/
int foo168(int * arr, int arr_len) {

		int ret = 0;
		int count = arr_len - 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
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
