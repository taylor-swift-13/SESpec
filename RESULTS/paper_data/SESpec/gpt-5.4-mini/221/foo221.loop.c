
/*@ logic integer parity(integer x) = x % 2; */

/*@ logic integer cnt_odd_with(int* a, integer i, integer hi) =
    hi <= i + 1 ? 0 :
      cnt_odd_with(a, i, hi - 1) +
      ((((a[i] ^ a[hi - 1]) % 2) == 1) ? 1 : 0);
*/

/*@ logic integer pair_count(int* a, integer hi) =
    hi <= 1 ? 0 :
      pair_count(a, hi - 1) + cnt_odd_with(a, hi - 1, hi);
*/
        
/*@
  requires arr_len >= 0;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
*/

int foo221(int * arr, int arr_len, int n) {

		int found = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant offset == arr_len;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant found >= 0;
          loop invariant (c == offset) ==> found >= 0;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns c, found;
            */
            for (int c = 0; c < offset; c++) {
			
            /*@ 
              loop assigns index, found;
              loop invariant 0 <= c < offset;
              loop invariant c + 1 <= index <= offset;
              loop invariant found >= 0;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
            
		}
            
		return found;
}
