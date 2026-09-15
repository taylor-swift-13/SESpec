
/*@
  logic integer cat(int* a, integer c, integer t) =
    t <= 0 ? 0 : cat(a, c, t - 1) + a[t - 1] * a[c - (t - 1) - 1];
*/



int foo55_c197(int n) {

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == n + 1;
          loop assigns c, arr[c];
            */
            for (int c = 1; c <= n; c++) {
			arr[c] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == n + 1;
          loop assigns arr[c], k;
            */
            for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
            
		}
            
		return arr[n];
}
