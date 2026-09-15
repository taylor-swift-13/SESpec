
/*@
  logic integer count_ge(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_ge(a, lo, hi - 1, v) + (a[hi - 1] >= v ? 1 : 0);
*/

/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@
  logic integer foo22_result(int* arr1, int arr1_len, int* arr, int arr_len, int Array, int n, int c) =
    c <= 0 ? -1 :
    (0 < c &&
     0 < Array &&
     ((0 >= n) || (arr1[0] <= arr[0])))
      ? (c == 1 ? arr1[0] : foo22_result(arr1, arr1_len, arr, arr_len, Array, n, c - 1))
      : (c == 1 ? arr[0] : foo22_result(arr1, arr1_len, arr, arr_len, Array, n, c - 1));
*/
/*@
  requires \valid(&arr1[0] + (0..arr1_len-1));
  requires \forall integer i; 0 <= i < arr1_len ==> 0 <= arr1[i] <= 100;
  requires arr1_len > 0;
  requires arr1_len < 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == foo22_result(arr1, arr1_len, arr, arr_len, Array, n, c);
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
