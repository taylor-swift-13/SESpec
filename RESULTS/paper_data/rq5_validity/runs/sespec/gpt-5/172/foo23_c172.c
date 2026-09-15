
/*@ predicate unchanged_arr{L1,L2}(int *a, integer n) =
      \forall integer i; 0 <= i < n ==> \at(a[i],L1) == \at(a[i],L2);
*/

/*@ logic integer taken_from_arr1(int* arr1, integer Array,
                                  int* arr, integer n,
                                  integer ct) =
      ct <= 0 ? 0 :
        ( taken_from_arr1(arr1, Array, arr, n, ct - 1) < Array
          &&
          ( ((ct - 1) - taken_from_arr1(arr1, Array, arr, n, ct - 1)) >= n
            ||
            arr1[taken_from_arr1(arr1, Array, arr, n, ct - 1)]
              <=
            arr[(ct - 1) - taken_from_arr1(arr1, Array, arr, n, ct - 1)] )
        )
        ? taken_from_arr1(arr1, Array, arr, n, ct - 1) + 1
        : taken_from_arr1(arr1, Array, arr, n, ct - 1);
*/

/*@ logic integer taken_from_arr(int* arr1, integer Array,
                                 int* arr, integer n,
                                 integer ct) =
      ct - taken_from_arr1(arr1, Array, arr, n, ct);
*/

/*@
  assigns \nothing;
  ensures arr == \at(arr,Pre);
  ensures arr1 == \at(arr1,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures arr1_len == \at(arr1_len,Pre);
  ensures n == \at(n,Pre);
  ensures Array == \at(Array,Pre);
  ensures p == \at(p,Pre);
  ensures unchanged_arr{Pre,Post}(arr, \at(arr_len,Pre));
  ensures unchanged_arr{Pre,Post}(arr1, \at(arr1_len,Pre));
  ensures p <= 0 ==> \result == -1;
  ensures \result == ((p <= 0) ? -1 : \result);
    ensures \result == ((p <= 0) ? -1 : \result);
*/
int foo23_c172(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int s = 0;

        /*@
          loop invariant 0 <= count;
          loop invariant 0 <= result;
          loop invariant 0 <= s;
          loop invariant result + s == count;
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant unchanged_arr{Pre,Here}(arr, \at(arr_len,Pre));
          loop invariant unchanged_arr{Pre,Here}(arr1, \at(arr1_len,Pre));
          loop assigns count, result, s;
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
