
/*@
logic integer sum(int *a, integer lo, integer hi) =
  lo >= hi ? 0 : sum(a, lo, hi - 1) + a[hi - 1];
*/

int foo229(int seed) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 1;
		
            /*@
          loop invariant 1 <= d <= seed + 1;
          loop invariant arr[0] == 1;
          loop invariant d <= arr_len;
          loop invariant \forall integer k; 0 <= k < d ==> arr[k] >= 1;
          loop invariant \forall integer k; 0 < k < d ==> arr[k] == sum(arr, 0, k + 1);
          loop invariant !(d <= seed) ==> d == seed + 1;
          loop assigns d, arr[0..seed];
            */
            for (int d = 1; d <= seed; d++) {
			
            /*@
          loop invariant \forall integer k; 0 <= k < d ==> arr[k] >= 1;
          loop invariant arr[d] >= \at(arr[d], Pre);
          loop invariant 0 <= c <= d;
          loop invariant arr[d] == \at(arr[d], Pre) + sum(arr, 0, c);
          loop assigns arr[d];
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[seed];
}
