
/*@
  logic integer count_occ(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_occ(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
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
  assigns \nothing;
  ensures p <= 0 ==> \result == -1;
  ensures p > 0 ==> (
    (\result == arr1[\at(result,Pre)] && \at(result,Pre) < Array && (\at(s,Pre) >= n || arr1[\at(result,Pre)] <= arr[\at(s,Pre)]) && \at(p,Pre) - 1 == \at(count,Pre))
    || (\result == arr[\at(s,Pre)] && !(\at(result,Pre) < Array && (\at(s,Pre) >= n || arr1[\at(result,Pre)] <= arr[\at(s,Pre)])) && \at(p,Pre) - 1 == \at(count,Pre))
    || \result == -1
  );
*/
int foo23(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int s = 0;

		
            
        /*@
          loop invariant (!(count < \at(p,Pre))) ==> ((s == 0)&&(result == 0)&&(p == \at(p,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer i; 0 <= i < arr1_len ==> arr1[i] == \at(arr1[i],Pre);
          loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i],Pre);
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
