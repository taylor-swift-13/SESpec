int findLastOccurrence(int * arr, int arr_len, int Array);

/*@ 
  requires arr_len >= 0;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
  requires \forall integer k, l; 0 <= k < l < arr_len ==> arr[k] <= arr[l];
  assigns \nothing;

  behavior found:
    assumes \exists integer k; 0 <= k < arr_len && arr[k] == Array;
    ensures 0 <= \result < arr_len;
    ensures arr[\result] == Array;
    ensures \forall integer k; 0 <= k < arr_len && arr[k] == Array ==> k <= \result;
    ensures \result == arr_len - 1 || arr[\result + 1] != Array;

  behavior not_found:
    assumes \forall integer k; 0 <= k < arr_len ==> arr[k] != Array;
    ensures \result == -1;

  complete behaviors;
  disjoint behaviors;
*/
int findLastOccurrence(int * arr, int arr_len, int Array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		/*@
		  loop invariant 0 <= i <= arr_len;
		  loop invariant -1 <= hi <= arr_len - 1;
		  loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= Array;
		  loop invariant \forall integer k; hi < k < arr_len ==> arr[k] > Array;
		  loop invariant (\exists integer j; 0 <= j < arr_len && arr[j] == Array) ==> (\exists integer j2; i <= j2 <= hi && arr[j2] == Array);
		  loop assigns i, hi, end;
		  loop variant hi - i;
		*/
		while (i <= hi) {
			end = (i + hi) / 2;
			/*@ assert i <= end <= hi; */
			/*@ assert 0 <= end < arr_len; */
			/*@ assert end == arr_len - 1 || end + 1 < arr_len; */
			if (arr[end] == Array) {
				if (end == arr_len - 1
						|| arr[end + 1] != Array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < Array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
}
