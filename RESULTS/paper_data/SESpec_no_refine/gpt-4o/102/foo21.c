
/*@
  logic integer unchanged_array{L1,L2}(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> \at(arr[i],L1) == \at(arr[i],L2);
*/

/*@
  logic integer is_sorted(int* arr, integer lo, integer hi) =
    lo >= hi - 1 ? 1 : (arr[lo] <= arr[lo + 1] && is_sorted(arr, lo + 1, hi));
*/

/*@
  logic integer is_partitioned(int* arr, integer lo, integer hi, integer pivot) =
    lo >= hi ? 1 : 
    (arr[lo] < pivot ? is_partitioned(arr, lo + 1, hi, pivot) : 0);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns ret, stop;
  ensures unchanged_array{Pre,Post}(arr, arr_len);
  ensures \result == 0 || (0 <= \result < arr_len && 
           ((\result > 0 && arr[\result] < arr[\result - 1]) || 
            (\result < arr_len - 1 && arr[\result] > arr[\result + 1])));
*/
int foo21(int * arr, int arr_len) {

		int ret = 0;
		int stop = arr_len - 1;
		
        /*@
          loop invariant 0 <= ret <= arr_len;
          loop invariant -1 <= stop < arr_len;
          loop invariant ret <= stop + 1;
          loop invariant unchanged_array{Pre,Here}(arr, arr_len);
          loop assigns ret, stop;
          loop variant stop - ret;
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
