
        /*@
        logic integer odd_pairs(int* arr, integer c, integer offset) =
          c >= offset ? 0 :
          odd_pairs(arr, c + 1, offset) +
          (\exists integer j; c < j < offset && ((arr[c] ^ arr[j]) % 2 == 1) ? 1 : 0);
        */
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo80(int * arr, int arr_len, int n) {

		int found = 0;
		int offset = arr_len;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant 0 <= found <= c * (offset - c);
          loop invariant found == \numof(0 <= i < c && c < j < offset && ((arr[c] ^ arr[j]) % 2 == 1));
          loop invariant offset == \at(arr_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns c, index, found;
            */
            for (int c = 0; c < offset; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= c <= offset;
              loop invariant found == \numof(0 <= i < c && c < j < offset && ((arr[c] ^ arr[j]) % 2 == 1));
              loop assigns c, found;
              loop variant offset - c;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
            
		}
            
		return found;
}
