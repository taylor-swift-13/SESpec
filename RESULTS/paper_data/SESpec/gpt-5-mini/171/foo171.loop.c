
/*@
  predicate same_array{L}(int *a, integer len) =
    \forall integer i; 0 <= i < len ==> a[i] == \at(a[i], L);
*/

/*@
  requires \at(arr1_len,Pre) > 0 && \at(arr1_len,Pre) < 100 &&
           \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo171(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

		int result = 0;
		int tmp = 0;

		
            
        /*@
          loop invariant (count < \at(c,Pre)) ==> (result + tmp == count);
          loop invariant (count < \at(c,Pre)) ==> (result >= 0);
          loop invariant (count < \at(c,Pre)) ==> (tmp >= 0);
          loop invariant (count < \at(c,Pre)) ==> ( (result < arr1_len && tmp < n && arr1[result] <= arr[tmp]) || (tmp >= n || !(result < arr1_len) || !(arr1[result] <= arr[tmp])) );
          loop invariant (count < \at(c,Pre)) ==> (result == result); 
          loop invariant (count < \at(c,Pre)) ==> (tmp == tmp) ;
          loop invariant (!(count < \at(c,Pre))) ==> ((tmp == 0)&&(result == 0)&&(c == \at(c,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant c == \at(c,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant same_array{Pre}(arr1, arr1_len);
          loop invariant same_array{Pre}(arr, arr_len);
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
