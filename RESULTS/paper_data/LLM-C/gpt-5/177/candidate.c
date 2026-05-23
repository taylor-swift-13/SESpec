/*@ predicate nondecreasing{L}(int *a, integer n) =
      \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@ 
  requires arr_len >= 0;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
  requires nondecreasing(arr, arr_len);

  assigns \nothing;

  behavior present:
    assumes \exists integer k; 0 <= k < arr_len && arr[k] == array;
    ensures \result != -1;
    ensures 0 <= \result < arr_len;
    ensures arr[\result] == array;
    ensures \result == arr_len - 1 || arr[\result + 1] != array;
    ensures \forall integer j; \result < j < arr_len ==> arr[j] != array;

  behavior absent:
    assumes \forall integer k; 0 <= k < arr_len ==> arr[k] != array;
    ensures \result == -1;

  complete behaviors present, absent;
  disjoint behaviors present, absent;
*/
int findLastOccurrence(int * arr, int arr_len, int array);

int findLastOccurrence(int * arr, int arr_len, int array) {

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
		/*@
		  loop invariant 0 <= i <= arr_len;
		  loop invariant -1 <= hi < arr_len;
		  loop invariant i <= hi + 1;
		  loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= array;
		  loop invariant \forall integer k; hi + 1 <= k < arr_len ==> arr[k] > array;
		  loop assigns i, hi, end;
		  loop variant hi - i + 1;
		*/
		while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
}
