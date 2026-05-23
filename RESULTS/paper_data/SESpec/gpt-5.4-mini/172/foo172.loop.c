
int foo172(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) {

		int result = 0;
		int s = 0;

		
            
        /*@
          loop invariant 0 <= count;
          loop invariant result >= 0;
          loop invariant s >= 0;
          loop invariant result + s == count;
          loop invariant result <= count;
          loop invariant s <= count;
          loop invariant (count < \at(p,Pre)) ==> (0 <= result <= count) ;
          loop invariant (count < \at(p,Pre)) ==> (0 <= s <= count) ;
          loop invariant (!(count < \at(p,Pre))) ==> ((s == 0)&&(result == 0)&&(p == \at(p,Pre))&&(n == \at(n,Pre))&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant p == \at(p,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k],Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
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
