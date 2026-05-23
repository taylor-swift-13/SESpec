
/*@
  // Helper logics for max and min over a prefix [0..hi] inclusive.
  logic integer max_prefix(int* a, integer hi) =
    hi <= 0 ? a[0] : (max_prefix(a, hi - 1) < a[hi] ? a[hi] : max_prefix(a, hi - 1));

  logic integer min_prefix(int* a, integer hi) =
    hi <= 0 ? a[0] : (min_prefix(a, hi - 1) > a[hi] ? a[hi] : min_prefix(a, hi - 1));
*/

/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
           assigns \nothing;   
  ensures \result == max_prefix(arr, arr_len-1) - min_prefix(arr, arr_len-1); 
    ensures \result == max_prefix(arr, arr_len-1) - min_prefix(arr, arr_len-1);  
*/
int foo233(int * arr, int arr_len) {

		int result = arr[0];
		int num = arr[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (n < \at(arr_len,Pre)) ==> (\true);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre) ;
          loop assigns n, result, num;
            */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
            
		return result - num;
}
