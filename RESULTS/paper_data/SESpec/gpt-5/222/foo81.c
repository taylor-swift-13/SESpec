
/*@
  logic integer count_odd_from(int* a, integer i, integer j, integer n) =
    j >= n ? 0
           : ( ((a[i] ^ a[j]) % 2) == 1 ? 1 : 0 ) + count_odd_from(a, i, j + 1, n);
*/

/*@
  logic integer count_odd_pairs_upto(int* a, integer n, integer i) =
    i <= 0 ? 0
           : count_odd_pairs_upto(a, n, i - 1)
             + count_odd_from(a, i - 1, i, n);
*/

        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == \result;
*/
int foo81(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= offset;
          loop invariant offset == \at(arr_len,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant \forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k], Pre);
          loop invariant 0 <= result;
          loop assigns index, result;
            */
            for (int index = 0; index < offset; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index < offset;
          loop invariant index + 1 <= c <= offset;
          loop invariant offset == \at(arr_len,Pre);
          loop invariant \forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k], Pre);
          loop invariant 0 <= result;
          loop assigns result, c;
            */
            for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
            
		}
            
		return result;
}
