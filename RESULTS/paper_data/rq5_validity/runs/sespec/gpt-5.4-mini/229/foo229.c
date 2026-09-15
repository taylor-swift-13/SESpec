
/*@ logic integer pow2(integer n) =
      n <= 0 ? 1 : 2 * pow2(n - 1);
*/
/*@
  requires seed >= 0;
  
  ensures \result >= 1;
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
          loop invariant !(d <= seed) ==> d == seed + 1;
          loop assigns d, arr[0..seed];
            */
            for (int d = 1; d <= seed; d++) {
			
            /*@
          loop invariant \forall integer k; 0 <= k < d ==> arr[k] >= 1;
          
          loop invariant 0 <= c <= d;
          loop assigns arr[d];
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[seed];
}
