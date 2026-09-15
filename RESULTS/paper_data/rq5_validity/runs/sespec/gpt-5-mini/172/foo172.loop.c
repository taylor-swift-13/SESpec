
/*@
  predicate Unchanged_int_array(int *a, integer len, int *orig) =
    \forall integer i; 0 <= i < len ==> a[i] == orig[i];
*/

/*@
  requires p >= 0;
  requires arr1_len >= 0;
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  requires \valid_read(arr1 + (0 .. arr1_len-1));
  requires \valid_read(arr + (0 .. arr_len-1));
  requires p <= arr1_len + arr_len;
*/
int foo172(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int s = 0;

        
        /*@
          loop invariant 0 <= count <= p;
          loop invariant 0 <= result + s <= count;
          loop invariant \forall integer i; 0 <= i < result ==> arr1[i] == \at(arr1[i], Pre);
          loop invariant \forall integer j; 0 <= j < s ==> arr[j] == \at(arr[j], Pre);
          loop invariant (count < \at(p,Pre)) ==> (result < arr1_len || s < arr_len);
          loop invariant (!(count < \at(p,Pre))) ==> ((s == 0)&&(result == 0)&&(p == \at(p,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant Unchanged_int_array(arr1, arr1_len, \at(arr1,Pre));
          loop invariant Unchanged_int_array(arr, arr_len, \at(arr,Pre));
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
