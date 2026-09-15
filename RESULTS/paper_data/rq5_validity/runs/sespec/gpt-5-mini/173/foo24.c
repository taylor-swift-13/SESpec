
/*@
  predicate unchanged_array_int{L1,L2}(int *a, integer len) =
    \forall integer i; 0 <= i < len ==> \at(a[i],L1) == \at(a[i],L2);
*/

/*@ predicate exists_in_arr{L}(int *a, integer len, integer v) =
      \exists integer i; 0 <= i < len && \at(a[i],L) == v;
*/

/*@ predicate exists_in_arr1{L}(int *a, integer len, integer v) =
      \exists integer i; 0 <= i < len && \at(a[i],L) == v;
*/

/*@
  requires \at(arr1_len,Pre) > 0 && \at(arr1_len,Pre) < 100 && \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires p >= 0;
  requires \valid(arr1 + (0 .. arr1_len-1));
  requires \valid(arr + (0 .. arr_len-1));
  requires Array >= 0 && Array <= arr1_len;
  requires n >= 0 && n <= arr_len;
  assigns \nothing;
  ensures unchanged_array_int{Pre,Post}(arr1, arr1_len);
  ensures unchanged_array_int{Pre,Post}(arr, arr_len);
  ensures arr_len == \at(arr_len,Pre);
  ensures arr == \at(arr,Pre);
  ensures arr1_len == \at(arr1_len,Pre);
  ensures arr1 == \at(arr1,Pre);
  ensures Array == \at(Array,Pre);
  ensures n == \at(n,Pre);
  ensures p == \at(p,Pre);
  ensures (\at(p,Pre) == 0) ==> (\result == -1);
*/
int foo24(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int tmp = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count <= p;
          loop invariant 0 <= result;
          loop invariant 0 <= tmp;
          loop invariant result + tmp == count;
          loop invariant (!(count < p)) ==> ((tmp == 0) && (result == 0) && (p == \at(p,Pre)) && (n == \at(n,Pre)) && (Array == \at(Array,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)) && (arr1_len == \at(arr1_len,Pre)) && (arr1 == \at(arr1,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant unchanged_array_int{Pre,Here}(arr1, arr1_len);
          loop invariant unchanged_array_int{Pre,Here}(arr, arr_len);
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
