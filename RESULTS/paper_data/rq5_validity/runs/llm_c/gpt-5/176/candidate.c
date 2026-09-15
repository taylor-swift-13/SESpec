int findLastOccurrence(int * arr, int arr_len, int array);

/*@ 
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires \forall integer i, j; 0 <= i <= j < arr_len ==> arr[i] <= arr[j];
  assigns \nothing;
  ensures (\result == -1) <==> (\forall integer k; 0 <= k < arr_len ==> arr[k] != array);
  ensures \result != -1 ==> 0 <= \result < arr_len 
                           && arr[\result] == array
                           && (\forall integer k; \result < k < arr_len ==> arr[k] != array);
*/
int findLastOccurrence(int * arr, int arr_len, int array) {

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
		/*@
		  loop invariant 0 <= found <= arr_len;
		  loop invariant -1 <= hi <= arr_len - 1;
		  loop invariant found <= hi + 1;
		  loop invariant \forall integer i; 0 <= i < found ==> arr[i] <= array;
		  loop invariant \forall integer i; hi + 1 <= i < arr_len ==> arr[i] > array;
		  loop invariant \forall integer k; 0 <= k < arr_len && arr[k] == array ==> found <= k <= hi;
		  loop assigns found, hi, end;
		  loop variant hi - found + 1;
		*/
		while (found <= hi) {
			end = (found + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					found = end + 1;
				}
			} else if (arr[end] < array) {
				found = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
}
