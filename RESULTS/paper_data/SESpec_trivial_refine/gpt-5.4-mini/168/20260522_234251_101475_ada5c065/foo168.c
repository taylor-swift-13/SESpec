

/*@
  requires arr_len > 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures 0 <= \result < arr_len;
  ensures \result == 0 || arr[\result] < arr[\result - 1];
  ensures \result == 0 || (\result > 0);
*/
int foo168(int * arr, int arr_len) {

	int ret = 0;
	int count = arr_len - 1;
		
	/*@
	  loop invariant 0 <= ret;
	  loop invariant count < arr_len;
	  loop assigns ret, count;
	*/
	while (ret <= count) {
		int r = ret + (count - ret) / 2;
		if (r < count && arr[r] > arr[r + 1]) {
			return r + 1;
		} else if (r > ret && arr[r] < arr[r - 1]) {
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
