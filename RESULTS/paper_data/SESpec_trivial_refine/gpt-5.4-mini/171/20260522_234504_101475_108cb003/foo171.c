
/*@
*/

/*@
  requires 0 <= arr1_len;
  requires 0 <= arr_len;
  requires 0 <= Array;
  requires 0 <= c <= arr1_len;
  requires 0 <= c <= arr_len;
  requires \valid_read(arr1 + (0 .. arr1_len - 1));
  requires \valid_read(arr + (0 .. arr_len - 1));
  assigns \nothing;
  ensures c <= 0 ==> \result == -1;
  ensures c > 0 ==> \result != -1;
  ensures c > 0 ==> ((\exists integer i; 0 <= i < arr1_len && \result == arr1[i]) || (\exists integer j; 0 <= j < arr_len && \result == arr[j]));
  ensures \result == -1 ==> c <= 0;
  ensures \result == \null ==> \false;
  ensures \result == PLACE_HOLDER_RESULT;
*/
int foo171(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

		int result = 0;
		int tmp = 0;

		/*@
		  loop invariant 0 <= count <= c;
		  loop invariant 0 <= result;
		  loop invariant 0 <= tmp;
		  loop invariant result + tmp == count;
		  loop assigns count, result, tmp;
		*/
		for (int count = 0; count < c; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == c - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == c - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
            
		return -1;
}
