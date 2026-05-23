
/*@
  logic integer count_ge(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_ge(a, lo, hi - 1, v) + (a[hi - 1] >= v ? 1 : 0);
*/

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
int foo22(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

		int result = 0;
		int tmp = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(count < \at(c,Pre))) ==> ((tmp == 0)&&(result == 0)&&(c == \at(c,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant c == \at(c,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer i; 0 <= i < \at(arr1_len,Pre) ==> arr1[i] == \at(arr1[i], Pre);
          loop invariant \forall integer i; 0 <= i < \at(arr_len,Pre) ==> arr[i] == \at(arr[i], Pre);
          loop assigns count, result, tmp;
            */
            for (int count = 0; count < c; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == c - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == c - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
            
		return -1;
}
