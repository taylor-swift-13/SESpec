
/*@ 
  predicate TRUE = \true;
*/

/*@ 
  requires arr_len == 1;
  requires \valid(&arr[0]);
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \exists integer imax, imin;
            0 <= imax < arr_len &&
            0 <= imin < arr_len;
  ensures \result >= 0;
  ensures \result <= 100 || \result > 100;
  ensures \result == 0 ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] == arr[0]);
*/
int foo233(int * arr, int arr_len) {

		int result = arr[0];
		int num = arr[0];
		
        /*@
          loop invariant 1 <= n;
          loop invariant result >= num;
          loop invariant result >= arr[0];
          loop invariant num <= arr[0];
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] <= result;
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] >= num;
          loop invariant \exists integer k; 0 <= k < n && arr[k] == result;
          loop invariant \exists integer k; 0 <= k < n && arr[k] == num;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (n >= arr_len) ==> result - num >= 0;
          loop assigns n, result, num;
        */
            for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < num) {
				num = arr[n];
			}
		}
            
		return result - num;
}
