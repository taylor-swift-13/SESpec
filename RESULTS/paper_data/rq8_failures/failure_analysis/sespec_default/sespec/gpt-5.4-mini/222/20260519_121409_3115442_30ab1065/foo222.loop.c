
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo222(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= offset;
          loop invariant result >= 0;
          loop invariant offset == arr_len;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
          loop assigns index, c, result;
            */
            for (int index = 0; index < offset; index++) {
			
            /*@ 
              loop invariant 0 <= index <= offset;
              loop invariant result >= 0;
              loop assigns index, result;
              loop variant offset - index;
            */
            /*@
              loop invariant index + 1 <= c <= offset;
              loop invariant result >= 0;
              loop assigns c, result;
              loop variant offset - c;
            */
            for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
            
		}
            
		return result;
}
