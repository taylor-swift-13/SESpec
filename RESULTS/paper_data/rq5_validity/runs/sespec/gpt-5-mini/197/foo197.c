
/*@ 
  logic integer catalan_num(integer n) =
    n <= 0 ? 1
          : \sum(0, n-1, \lambda integer k; catalan_num(k) * catalan_num(n - k - 1));
*/
/*@
  requires n >= 0;
  assigns \nothing;
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
