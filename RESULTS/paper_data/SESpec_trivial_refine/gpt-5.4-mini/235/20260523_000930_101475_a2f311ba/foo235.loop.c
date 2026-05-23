
/*@
*/

int foo235(int * arr, int arr_len) {

		int result = arr[0];
		int sum = arr[0];
		
        /*@
          loop invariant 1 <= n <= arr_len;
          loop invariant \forall integer i; 0 <= i < n ==> result >= arr[i];
          loop invariant \forall integer i; 0 <= i < n ==> sum <= arr[i];
          loop assigns n, result, sum;
          loop variant arr_len - n;
        */
        for (int n = 1; n < arr_len; n++) {
			if (arr[n] > result) {
				result = arr[n];
			}
			if (arr[n] < sum) {
				sum = arr[n];
			}
		}
            
		return result - sum;
}
