
        /*@
        */

/*@
  requires \valid_read(arr1 + (0 .. arr1_len - 1));
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires 0 <= p <= arr1_len;
  requires 0 <= p <= arr_len;
  assigns \nothing;
  ensures p <= 0 ==> \result == -1;
  ensures p > 0 ==> \result != -1;
  ensures \result == -1 ==> p <= 0;
  ensures \result == -1;
*/
int foo172(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int s = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count <= p;
          loop invariant 0 <= result;
          loop invariant 0 <= s;
          loop invariant result + s == count;
          loop assigns result, s;
            */
            for (int count = 0; count < p; count++) {
			if (result < Array
					&& (s >= n || arr1[result] <= arr[s])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[s];
				}
				s++;
			}
		}
            
		return -1;
}
