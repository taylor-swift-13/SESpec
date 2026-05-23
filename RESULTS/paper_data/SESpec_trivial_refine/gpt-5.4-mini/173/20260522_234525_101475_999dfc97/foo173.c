
        /*@
        */

/*@
  requires 0 <= p;
  requires p <= arr1_len;
  requires p <= arr_len;
  requires p > 0 ==> \valid_read(arr1 + (0 .. p-1));
  requires p > 0 ==> \valid_read(arr + (0 .. p-1));
  assigns \nothing;
  ensures p <= 0 ==> \result == -1;
  ensures p > 0 ==> \result != -1;
  ensures p > 0 ==> (\exists integer i; 0 <= i < p && (\result == arr1[i] || \result == arr[i]));
  ensures \result == -1 <==> p <= 0;
  ensures p > 0 ==> (\result == -1) == \false;
  ensures p > 0 ==> (\result == arr1[0] || \result == arr[0] || \result == arr1[p-1] || \result == arr[p-1] || \result == -1 || \result == arr1[0] || \result == arr[0]);
*/
int foo173(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int tmp = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant count >= 0;
          loop invariant (p < 0) || count <= p;
          loop invariant result >= 0;
          loop invariant tmp >= 0;
          loop invariant result + tmp == count;
          loop assigns count, result, tmp;
            */
            for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
            
		return -1;
}
