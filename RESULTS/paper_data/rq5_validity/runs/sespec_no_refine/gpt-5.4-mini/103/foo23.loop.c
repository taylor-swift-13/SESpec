
/*@
  logic integer arr1_prefix_unchanged{L}(int *arr1, integer len, integer i) =
    i <= 0 ? 1 :
    (arr1[i - 1] == \at(arr1[i - 1], Pre) && arr1_prefix_unchanged(arr1, len, i - 1));

  logic integer arr_prefix_unchanged{L}(int *arr, integer len, integer i) =
    i <= 0 ? 1 :
    (arr[i - 1] == \at(arr[i - 1], Pre) && arr_prefix_unchanged(arr, len, i - 1));
*/

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo23(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int s = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (count < \at(p,Pre)) ==> (result >= 0 && result <= \at(arr1_len,Pre));
          loop invariant (count < \at(p,Pre)) ==> (s >= 0 && s <= \at(arr_len,Pre));
          loop invariant (!(count < \at(p,Pre))) ==> ((s == 0)&&(result == 0)&&(p == \at(p,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant arr_prefix_unchanged(arr, arr_len, arr_len);
          loop invariant arr1_prefix_unchanged(arr1, arr1_len, arr1_len);
          loop assigns count, result, s;
            */
            for (int count = 0; count < p; count++) {
			if (result < Array
					&& (s >= n || arr1[result] <= arr[s])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[s];
				}
				s++;
			}
		}
            
		return -1;
}
