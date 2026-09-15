
/*@ logic integer arr_max(int* a, integer lo, integer hi) =
      lo >= hi ? -2147483648
               : ( a[hi-1] > arr_max(a, lo, hi-1) ? a[hi-1] : arr_max(a, lo, hi-1) );
*/

/*@ logic integer arr_min(int* a, integer lo, integer hi) =
      lo >= hi ? 2147483647
               : ( a[hi-1] < arr_min(a, lo, hi-1) ? a[hi-1] : arr_min(a, lo, hi-1) );
*/

/*@ predicate unchanged_array(int* a, integer lo, integer hi, int* a_pre) =
      \forall integer i; lo <= i < hi ==> a[i] == a_pre[i];
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid(arr + (0..\at(arr_len,Pre)-1));
  requires arr_len == \at(arr_len,Pre);
  requires arr == \at(arr,Pre);
*/
int foo93(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		
            
        /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant big == arr_max(arr, 0, n);
          loop invariant sum == arr_min(arr, 0, n);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array(arr, 0, arr_len, \at(arr,Pre));
          loop assigns n, big, sum;
        */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > big) {
				big = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
            
		return big - sum;
}
