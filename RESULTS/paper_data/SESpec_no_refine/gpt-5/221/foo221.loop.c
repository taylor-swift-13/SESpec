
/*@
        
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo221(int * arr, int arr_len, int n) {

		int found = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant offset == arr_len;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns c, index, found;
            */
            for (int c = 0; c < offset; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c + 1 <= index <= offset;
          loop assigns found, index;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
            
		}
            
		return found;
}
