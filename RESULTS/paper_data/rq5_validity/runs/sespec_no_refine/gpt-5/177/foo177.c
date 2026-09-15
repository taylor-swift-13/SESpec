
/*@
  // no extra logic/predicate needed
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures
    ( \exists integer j; 0 <= j < arr_len && arr[j] == array ) ==>
      ( 0 <= \result < arr_len
        && arr[\result] == array
        && ( \result == arr_len - 1 || arr[\result + 1] > array )
        && ( \forall integer k; 0 <= k < arr_len && arr[k] == array ==> k <= \result ) );
  ensures
    ( \forall integer k; 0 <= k < arr_len ==> arr[k] != array ) ==> \result == -1;
  ensures \result == -1 || (0 <= \result < arr_len);
*/
int foo177(int * arr, int arr_len, int array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant arr == \at(arr,Pre);
              loop invariant arr_len == \at(arr_len,Pre);
              loop invariant array == \at(array,Pre);
              loop invariant \valid_read(arr + (0 .. arr_len-1));
              loop invariant 0 <= arr_len-1 ==> -1 <= hi < arr_len;
              loop invariant 0 <= arr_len-1 ==> 0 <= i <= hi + 1;
              loop invariant 0 <= arr_len-1 ==> \forall integer k; 0 <= k < i ==> arr[k] <= array;
              loop invariant 0 <= arr_len-1 ==> \forall integer k; hi < k < arr_len ==> arr[k] > array;
              loop assigns end, i, hi;
            */
            while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
            
		return -1;
}
