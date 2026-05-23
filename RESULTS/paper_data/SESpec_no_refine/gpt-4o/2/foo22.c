
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];

  logic integer cntpos(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cntpos(a, lo, hi - 1) + (a[hi - 1] > 0 ? 1 : 0);
*/

/*@
  requires \valid(&arr1[0] + (0..arr1_len-1));
  requires \forall integer i; 0 <= i < arr1_len ==> 0 <= arr1[i] <= 100;
  requires arr1_len > 0;
  requires arr1_len < 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires c >= 0 && c <= arr1_len && c <= arr_len;
  assigns result, tmp;
  ensures \result == (c > 0 ? 
                      (c - 1 < c && result < Array && (tmp >= n || arr1[result] <= arr[tmp]) ? arr1[result] :
                      (c - 1 < c && !(result < Array && (tmp >= n || arr1[result] <= arr[tmp])) ? arr[tmp] : -1)) : -1);
*/
int foo22(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

		int result = 0;
		int tmp = 0;

		/*@
          loop invariant 0 <= count <= c;
          loop invariant 0 <= result <= arr1_len;
          loop invariant 0 <= tmp <= arr_len;
          loop invariant c >= 0 && c <= arr1_len && c <= arr_len;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k], Pre);
          loop assigns count, result, tmp;
          loop variant c - count;
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
