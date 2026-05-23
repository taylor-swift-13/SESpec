
/*@
  logic integer partial_sum(int* a, integer c, integer k) =
    k <= 0 ? 0
           : \sum(0, k-1, \lambda integer i; a[i] * a[c - i - 1]);
*/


        

int foo197(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop assigns c, arr[0 .. n];
            */
            for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop assigns k, arr[0 .. n];
            */
            for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
            
		}
            
		return arr[n];
}
