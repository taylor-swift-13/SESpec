
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo223(int * arr, int arr_len, int n) {

	int result = 0;
	int offset = arr_len;
	
        /*@
          loop invariant 0 <= c;
          loop invariant offset == arr_len;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant result >= 0;
          loop assigns c, result;
        */
        for (int c = 0; c < offset; c++) {
			
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant 0 <= result;
          loop assigns c, result;
        */
        for (int index = c + 1; index < offset; index++) {
			if ((arr[c] ^ arr[index]) % 2 == 1) {
				result++;
			}
		}
            
	}
            
	return result;
}
