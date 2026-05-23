
/*@
  logic integer pow2(integer n) =
    n <= 0 ? 1 : 2 * pow2(n - 1);

  logic integer prefix_sum{L}(int* a, integer d, integer c) =
    c <= 0 ? 0 : prefix_sum(a, d, c - 1) + a[c - 1];
*/

/*@ 
*/
        


int foo227(int b) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
int arr_len = b + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= d <= b + 1;
          loop invariant arr[0] == 1;
          loop invariant \forall integer k; 1 <= k < d ==> arr[k] == pow2(k - 1);
          loop assigns d, c, arr[..];
            */
            for (int d = 1; d <= b; d++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= d <= b;
          loop invariant 0 <= c <= d;
          loop invariant arr[0] == 1;
          loop invariant \forall integer k; 1 <= k < d ==> arr[k] == pow2(k - 1);
          loop invariant arr[d] == prefix_sum(arr, d, c);
          loop assigns arr[..];
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[b];
}
