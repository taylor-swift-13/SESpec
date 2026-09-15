
/*@ predicate valid_read_slice{L}(int *a, integer n) =
      n >= 0 && \valid_read(a + (0..n-1));
*/

/*@ predicate sorted_nondecr{L}(int *a, integer n) =
      \forall integer i,j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires sorted_nondecr{Pre}(arr, arr_len);
  assigns \nothing;
  ensures (\result != -1 ==>
           0 <= \result < arr_len &&
           arr[\result] == array &&
           (\result == arr_len - 1 || arr[\result + 1] != array));
  ensures \result == -1 || (\exists integer k; 0 <= k < arr_len && arr[k] == array);
*/
int foo27(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant 0 <= found;
          loop invariant hi <= \at(arr_len,Pre) - 1;
          loop invariant (found <= hi) ==> (0 <= end && end < \at(arr_len,Pre));
          loop assigns end, found, hi;
            */
            while (found <= hi) {
			end = (found + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					found = end + 1;
				}
			} else if (arr[end] < array) {
				found = end + 1;
			} else {
				hi = end - 1;
			}
		}
            
		return -1;
}
