

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires \forall integer i; 0 <= i < arr_len-1 ==> arr[i] <= arr[i+1];
  assigns \nothing;
  ensures 0 <= \result < arr_len;
*/
int foo170(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		
            
        /*@
          loop invariant 0 <= ret <= arr_len;
          loop invariant -1 <= stop < arr_len;
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns ret, stop;
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
