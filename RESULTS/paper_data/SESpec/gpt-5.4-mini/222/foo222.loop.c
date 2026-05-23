
/*@
  logic integer odd_with_index(int* a, integer idx, integer lo, integer hi) =
    hi <= lo ? 0 :
    odd_with_index(a, idx, lo, hi - 1) +
      ((((a[idx] ^ a[hi - 1]) % 2) == 1) ? 1 : 0);

  logic integer paircount_prefix(int* a, integer i, integer n) =
    i <= 0 ? 0 :
    paircount_prefix(a, i - 1, n) +
      odd_with_index(a, i - 1, i, n);
*/

/*@ 
  requires 0 <= arr_len;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
*/

int foo222(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= offset;
          loop invariant result >= 0;
          loop invariant result == paircount_prefix(arr, index, offset);
          loop invariant \forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k],Pre);
          loop invariant \forall integer k; 0 <= k < offset ==> 0 <= arr[k] <= 100;
          loop invariant index <= offset;
          loop invariant offset == \at(arr_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns index, result;
            */
            for (int index = 0; index < offset; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= index + 1 && c <= offset;
          loop invariant result >= 0;
          loop invariant result == paircount_prefix(arr, index, offset) + odd_with_index(arr, index, index + 1, c);
          loop invariant \forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k],Pre);
          loop assigns c, result;
            */
            for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
            
		}
            
		return result;
}
