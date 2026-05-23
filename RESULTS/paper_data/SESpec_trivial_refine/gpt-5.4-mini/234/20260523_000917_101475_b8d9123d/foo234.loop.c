
/*@
  requires arr_len > 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  ensures \result >= 0;
*/

int foo234(int * arr, int arr_len) {

		int big = arr[0];
		int sum = arr[0];
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant \forall integer i; 0 <= i < n ==> big >= arr[i];
          loop invariant \forall integer i; 0 <= i < n ==> sum <= arr[i];
          loop assigns n, big, sum;
            */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > big) {
				big = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
            
		return big - sum;
}
