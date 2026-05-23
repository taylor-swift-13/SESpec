
/*@
  logic integer count_lt(int *a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_lt(a, lo, hi - 1, v) + (a[hi - 1] < v ? 1 : 0);
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
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo24(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int tmp = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(count < \at(p,Pre))) ==> ((tmp == 0)&&(result == 0)&&(p == \at(p,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
          loop invariant \forall integer i; 0 <= i < arr1_len ==> arr1[i] == \at(arr1[i], Pre);
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
