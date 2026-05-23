
/*@
logic integer sum_prefix(int *a, integer n) = 
  (n <= 0) ? 0 : sum_prefix(a, n - 1) + a[n - 1];
*/

/*@
  requires 0 <= b;
*/

int foo227(int b) {

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
int arr_len = b + 1;
		arr[0] = 1;
		
            /*@
              loop invariant 1 <= d <= b + 1;
              loop invariant arr[0] == 1;
              loop assigns d, arr[0 .. b];
            */
            for (int d = 1; d <= b; d++) {
			
            /*@
              loop invariant 0 <= c <= d;
              loop invariant arr[0] == 1;
              loop assigns c, arr[d];
            */
            for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
            
		return arr[b];
}
