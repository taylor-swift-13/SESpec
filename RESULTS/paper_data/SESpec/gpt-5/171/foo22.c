

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
  ensures arr1 == \at(arr1,Pre) && arr == \at(arr,Pre) &&
          arr1_len == \at(arr1_len,Pre) && arr_len == \at(arr_len,Pre) &&
          Array == \at(Array,Pre) && n == \at(n,Pre) && c == \at(c,Pre);
  ensures \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k],Pre);
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
  ensures c <= 0 ==> \result == -1;
  ensures \result == \result;
*/
int foo22(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) {

		int result = 0;
		int tmp = 0;

        /* >>> LOOP INVARIANT TO FILL <<< */
        /*@
          loop invariant 0 <= count;
          loop invariant (count < \at(c,Pre)) ==> (0 <= result && 0 <= tmp && result + tmp == count);
          loop invariant (!(count < \at(c,Pre))) ==> ((tmp == 0)&&(result == 0)&&(c == \at(c,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant c == \at(c,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre) ;
          loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k], Pre) ;
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
